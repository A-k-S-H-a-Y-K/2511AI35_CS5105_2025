#include <stdio.h>

long long uniquePathsGrid(int rowCount, int colCount) {
    long long dpPathCount[rowCount][colCount];

    for (int r = 0; r < rowCount; r++) {
        for (int c = 0; c < colCount; c++) {
            dpPathCount[r][c] = 1;
        }
    }

    for (int r = 1; r < rowCount; r++) {
        for (int c = 1; c < colCount; c++) {
            dpPathCount[r][c] = dpPathCount[r - 1][c] + dpPathCount[r][c - 1];
        }
    }

    return dpPathCount[rowCount - 1][colCount - 1];
}

int main() {
    int rows = 3;
    int cols = 3;
    printf("%lld\n", uniquePathsGrid(rows, cols));
    return 0;
}
