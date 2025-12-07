import pandas as pd
import streamlit as st
#
st.title("Student Grouping App")

# File uploader
uploaded_file = st.file_uploader("Upload your input CSV", type="csv")

# Number of groups input
num_groups = st.number_input("Number of groups to be created", min_value=1, value=5, step=1)

def convert_df_to_csv_bytes(df):
    """Convert DataFrame to bytes for Streamlit download."""
    return df.to_csv(index=False).encode('utf-8')

if uploaded_file and st.button("Process"):
    df = pd.read_csv(uploaded_file)
    df.index = df.index + 1
    total = len(df)

    # Extract department code
    df["Dept"] = df["Roll"].astype(str).str[4:6]
    depts = sorted(df["Dept"].unique())

    # Shuffle students deterministically
    df = df.sample(frac=1, random_state=42).reset_index(drop=True)

    # -------------------- Uniform Distribution --------------------
    n = num_groups
    min_group_size = total // n
    extra_students = total % n
    target_sizes = [min_group_size + 1 if i < extra_students else min_group_size for i in range(n)]

    dept_students = {dept: df[df["Dept"] == dept].values.tolist() for dept in depts}

    def create_balanced_group(target_size, dept_students):
        group_students = []
        for dept in sorted(dept_students, key=lambda d: len(dept_students[d]), reverse=True):
            while dept_students[dept] and len(group_students) < target_size:
                group_students.append(dept_students[dept].pop())
            if len(group_students) == target_size:
                break
        return group_students

    balanced_groups = []
    for size in target_sizes:
        group = create_balanced_group(size, dept_students)
        balanced_groups.append(group)

    # Handle leftover
    leftover = []
    for students in dept_students.values():
        leftover.extend(students)
    if leftover:
        balanced_groups[-1].extend(leftover)

    # Prepare uniform summary
    uniform_summary = []
    for i, group in enumerate(balanced_groups, start=1):
        group_df = pd.DataFrame(group, columns=df.columns)
        row = {"Group": f"Group {i}"}
        counts = group_df["Dept"].value_counts().to_dict()
        for dept in depts:
            row[dept] = counts.get(dept, 0)
        row["Total Students"] = len(group_df)
        uniform_summary.append(row)

    uniform_summary_df = pd.DataFrame(uniform_summary)
    st.subheader("Uniform Distribution")
    st.dataframe(uniform_summary_df)

    # Download button for uniform summary
    csv_bytes = convert_df_to_csv_bytes(uniform_summary_df)
    st.download_button(
        label="Download Uniform Distribution CSV",
        data=csv_bytes,
        file_name="uniform_distribution_summary.csv",
        mime="text/csv"
    )

    # -------------------- Mix Distribution --------------------
    dept_students_mix = {dept: df[df["Dept"] == dept].values.tolist() for dept in depts}
    randomized_groups = [[] for _ in range(n)]

    # Floor distribution per dept
    dept_floor_counts = {dept: len(students) // n for dept, students in dept_students_mix.items()}
    dept_remainders = {dept: len(students) % n for dept, students in dept_students_mix.items()}

    # Step 1: Fill floor count
    for group_idx in range(n):
        for dept in depts:
            take = dept_floor_counts[dept]
            if take > 0:
                randomized_groups[group_idx].extend(dept_students_mix[dept][:take])
                dept_students_mix[dept] = dept_students_mix[dept][take:]

    # Step 2: Distribute remainder
    for dept, rem in dept_remainders.items():
        for i in range(rem):
            randomized_groups[i].append(dept_students_mix[dept].pop(0))

    # Step 3: Adjust to target sizes
    for i, group in enumerate(randomized_groups):
        target_size = target_sizes[i]
        current_size = len(group)
        if current_size < target_size:
            for j in range(n):
                if j == i:
                    continue
                while len(group) < target_size and randomized_groups[j]:
                    group.append(randomized_groups[j].pop(0))
        elif current_size > target_size:
            for j in range(i + 1, n):
                while len(group) > target_size and len(randomized_groups[j]) < target_sizes[j]:
                    randomized_groups[j].append(group.pop())

    # Prepare mix summary
    mix_summary = []
    for i, group in enumerate(randomized_groups, start=1):
        group_df = pd.DataFrame(group, columns=df.columns)
        row = {"Group": f"Group {i}"}
        counts = group_df["Dept"].value_counts().to_dict()
        for dept in depts:
            row[dept] = counts.get(dept, 0)
        row["Total Students"] = len(group_df)
        mix_summary.append(row)

    mix_summary_df = pd.DataFrame(mix_summary)
    st.subheader("Mix Distribution")
    st.dataframe(mix_summary_df)

    # Download button for mix summary
    csv_bytes_mix = convert_df_to_csv_bytes(mix_summary_df)
    st.download_button(
        label="Download Mix Distribution CSV",
        data=csv_bytes_mix,
        file_name="mix_distribution_summary.csv",
        mime="text/csv"
    )
