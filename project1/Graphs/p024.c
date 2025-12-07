#include <stdio.h>
#include <string.h>

int courseScheduleCanFinish(int courseCount, int **prerequisiteList, int prereqCount) {
    int inDegree[courseCount];
    memset(inDegree, 0, sizeof(inDegree));

    for (int i = 0; i < prereqCount; i++) {
        inDegree[prerequisiteList[i][0]]++;
    }

    int queue[courseCount];
    int qIdx = 0, fIdx = 0;

    for (int courseIdx = 0; courseIdx < courseCount; courseIdx++) {
        if (inDegree[courseIdx] == 0) {
            queue[qIdx++] = courseIdx;
        }
    }

    int completedCount = 0;

    while (fIdx < qIdx) {
        int currCourse = queue[fIdx++];
        completedCount++;

        for (int i = 0; i < prereqCount; i++) {
            if (prerequisiteList[i][1] == currCourse) {
                inDegree[prerequisiteList[i][0]]--;
                if (inDegree[prerequisiteList[i][0]] == 0) {
                    queue[qIdx++] = prerequisiteList[i][0];
                }
            }
        }
    }

    return completedCount == courseCount;
}

int main() {
    int prereq[3][2] = {{1,0}, {2,1}, {3,2}};
    int *pPtr[3];
    for (int i = 0; i < 3; i++) pPtr[i] = (int *)prereq[i];

    printf("%d\n", courseScheduleCanFinish(4, pPtr, 3));
    return 0;
}
