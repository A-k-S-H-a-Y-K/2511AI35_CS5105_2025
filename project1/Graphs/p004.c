#include <stdio.h>
#include <string.h>

void findNearestDistance(int rows, int cols, int **binaryGrid, int **distanceGrid) {
    typedef struct { int r, c; } Cell;
    Cell queue[rows * cols];
    int qIdx = 0, fIdx = 0;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            distanceGrid[r][c] = binaryGrid[r][c] == 1 ? 0 : -1;
            if (binaryGrid[r][c] == 1) {
                queue[qIdx].r = r;
                queue[qIdx].c = c;
                qIdx++;
            }
        }
    }

    int dirs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    while (fIdx < qIdx) {
        Cell curr = queue[fIdx++];

        for (int d = 0; d < 4; d++) {
            int nr = curr.r + dirs[d][0];
            int nc = curr.c + dirs[d][1];

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && distanceGrid[nr][nc] == -1) {
                distanceGrid[nr][nc] = distanceGrid[curr.r][curr.c] + 1;
                queue[qIdx].r = nr;
                queue[qIdx].c = nc;
                qIdx++;
            }
        }
    }
}

int main() {
    int grid[3][3] = {{1,0,1}, {0,1,0}, {1,0,1}};
    int dist[3][3];
    int *gPtr[3], *dPtr[3];
    for (int i = 0; i < 3; i++) {
        gPtr[i] = (int *)grid[i];
        dPtr[i] = (int *)dist[i];
    }

    findNearestDistance(3, 3, gPtr, dPtr);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) printf("%d ", dist[i][j]);
        printf("\n");
    }
    return 0;
}
