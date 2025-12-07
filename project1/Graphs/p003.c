#include <stdio.h>
#include <string.h>

typedef struct {
    int row, col, time;
} RottenCell;

int minRottenOranges(int rows, int cols, int **gridData) {
    RottenCell rottenQueue[rows * cols];
    int queueIdx = 0, freshOranges = 0;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (gridData[r][c] == 2) {
                rottenQueue[queueIdx].row = r;
                rottenQueue[queueIdx].col = c;
                rottenQueue[queueIdx].time = 0;
                queueIdx++;
            } else if (gridData[r][c] == 1) {
                freshOranges++;
            }
        }
    }

    if (freshOranges == 0) return 0;

    int directions[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int frontIdx = 0, maxTime = 0;

    while (frontIdx < queueIdx) {
        RottenCell curr = rottenQueue[frontIdx++];

        for (int dirIdx = 0; dirIdx < 4; dirIdx++) {
            int newRow = curr.row + directions[dirIdx][0];
            int newCol = curr.col + directions[dirIdx][1];

            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && gridData[newRow][newCol] == 1) {
                gridData[newRow][newCol] = 2;
                rottenQueue[queueIdx].row = newRow;
                rottenQueue[queueIdx].col = newCol;
                rottenQueue[queueIdx].time = curr.time + 1;
                maxTime = curr.time + 1;
                queueIdx++;
                freshOranges--;
            }
        }
    }

    return freshOranges == 0 ? maxTime : -1;
}

int main() {
    int grid[3][3] = {{2,1,1}, {1,1,0}, {0,1,1}};
    int *gridPtr[3];
    for (int i = 0; i < 3; i++) gridPtr[i] = (int *)grid[i];

    printf("%d\n", minRottenOranges(3, 3, gridPtr));
    return 0;
}
