#include <stdio.h>
#include <limits.h>

int minimumTrianglePath(int rowCount, int triangle[][rowCount]) {
    int dpMinSum[rowCount][rowCount];

    dpMinSum[rowCount - 1][0] = triangle[rowCount - 1][0];

    for (int r = rowCount - 2; r >= 0; r--) {
        for (int c = 0; c <= r; c++) {
            int pathDown = dpMinSum[r + 1][c];
            int pathDiag = dpMinSum[r + 1][c + 1];
            dpMinSum[r][c] = triangle[r][c] + ((pathDown < pathDiag) ? pathDown : pathDiag);
        }
    }

    return dpMinSum[0][0];
}

int main() {
    int triangle[][4] = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    int rows = 4;
    printf("%d\n", minimumTrianglePath(rows, triangle));
    return 0;
}
