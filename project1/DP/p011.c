#include <stdio.h>
#include <limits.h>

int maximumPathMatrix(int rowCount, int colCount, int matrix[][colCount]) {
    int dpMaxSum[rowCount][colCount];

    for (int c = 0; c < colCount; c++) {
        dpMaxSum[0][c] = matrix[0][c];
    }

    for (int r = 1; r < rowCount; r++) {
        for (int c = 0; c < colCount; c++) {
            int pathDown = dpMaxSum[r - 1][c];
            int pathDiagLeft = (c > 0) ? dpMaxSum[r - 1][c - 1] : INT_MIN;
            int pathDiagRight = (c < colCount - 1) ? dpMaxSum[r - 1][c + 1] : INT_MIN;

            int maxPrev = (pathDown > pathDiagLeft) ? pathDown : pathDiagLeft;
            maxPrev = (maxPrev > pathDiagRight) ? maxPrev : pathDiagRight;

            dpMaxSum[r][c] = matrix[r][c] + maxPrev;
        }
    }

    int finalMax = INT_MIN;
    for (int c = 0; c < colCount; c++) {
        finalMax = (dpMaxSum[rowCount - 1][c] > finalMax) ? dpMaxSum[rowCount - 1][c] : finalMax;
    }

    return finalMax;
}

int main() {
    int matrix[][3] = {{1, 2, 10}, {1, 10, 10}, {10, 1, 1}};
    int rows = 3;
    int cols = 3;
    printf("%d\n", maximumPathMatrix(rows, cols, matrix));
    return 0;
}
