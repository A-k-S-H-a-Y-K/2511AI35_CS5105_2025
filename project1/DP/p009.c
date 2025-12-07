#include <stdio.h>
#include <limits.h>

int minimumCostPath(int rowCount, int colCount, int grid[][colCount]) {
    int dpCost[rowCount][colCount];

    for (int r = 0; r < rowCount; r++) {
        for (int c = 0; c < colCount; c++) {
            dpCost[r][c] = INT_MAX;
        }
    }

    dpCost[0][0] = grid[0][0];

    for (int c = 1; c < colCount; c++) {
        dpCost[0][c] = dpCost[0][c - 1] + grid[0][c];
    }

    for (int r = 1; r < rowCount; r++) {
        dpCost[r][0] = dpCost[r - 1][0] + grid[r][0];
    }

    for (int r = 1; r < rowCount; r++) {
        for (int c = 1; c < colCount; c++) {
            int fromTop = dpCost[r - 1][c];
            int fromLeft = dpCost[r][c - 1];
            dpCost[r][c] = grid[r][c] + ((fromTop < fromLeft) ? fromTop : fromLeft);
        }
    }

    return dpCost[rowCount - 1][colCount - 1];
}

int main() {
    int grid[][3] = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int rows = 3;
    int cols = 3;
    printf("%d\n", minimumCostPath(rows, cols, grid));
    return 0;
}
