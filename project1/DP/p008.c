#include <stdio.h>

long long mazePathsObstacles(int rowCount, int colCount, int maze[][colCount]) {
    long long dpMazePath[rowCount][colCount];

    for (int r = 0; r < rowCount; r++) {
        for (int c = 0; c < colCount; c++) {
            dpMazePath[r][c] = 0;
        }
    }

    if (maze[0][0] != -1) dpMazePath[0][0] = 1;

    for (int r = 0; r < rowCount; r++) {
        for (int c = 0; c < colCount; c++) {
            if (maze[r][c] == -1) {
                dpMazePath[r][c] = 0;
            } else if (r == 0 && c == 0) {
                dpMazePath[r][c] = 1;
            } else {
                long long pathFromTop = (r > 0) ? dpMazePath[r - 1][c] : 0;
                long long pathFromLeft = (c > 0) ? dpMazePath[r][c - 1] : 0;
                dpMazePath[r][c] = pathFromTop + pathFromLeft;
            }
        }
    }

    return dpMazePath[rowCount - 1][colCount - 1];
}

int main() {
    int maze[][3] = {{0, 0, 0}, {0, -1, 0}, {0, 0, 0}};
    int rows = 3;
    int cols = 3;
    printf("%lld\n", mazePathsObstacles(rows, cols, maze));
    return 0;
}
