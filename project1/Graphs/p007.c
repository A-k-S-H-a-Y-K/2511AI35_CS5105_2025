#include <stdio.h>
#include <string.h>

typedef struct { int r, c, dist; } MazeCell;

int shortestPathBinaryMaze(int rows, int cols, int **gridData, int srcRow, int srcCol, int dstRow, int dstCol) {
    if (gridData[srcRow][srcCol] == 0 || gridData[dstRow][dstCol] == 0) return -1;

    MazeCell queue[rows * cols];
    int qIdx = 0, fIdx = 0;
    int visited[rows][cols];
    memset(visited, 0, sizeof(visited));

    queue[qIdx].r = srcRow;
    queue[qIdx].c = srcCol;
    queue[qIdx].dist = 0;
    qIdx++;
    visited[srcRow][srcCol] = 1;

    int dirs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    while (fIdx < qIdx) {
        MazeCell curr = queue[fIdx++];

        if (curr.r == dstRow && curr.c == dstCol) return curr.dist;

        for (int d = 0; d < 4; d++) {
            int nr = curr.r + dirs[d][0];
            int nc = curr.c + dirs[d][1];

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && gridData[nr][nc] == 1 && !visited[nr][nc]) {
                visited[nr][nc] = 1;
                queue[qIdx].r = nr;
                queue[qIdx].c = nc;
                queue[qIdx].dist = curr.dist + 1;
                qIdx++;
            }
        }
    }
    return -1;
}

int main() {
    int grid[5][4] = {{1,1,1,1}, {1,1,0,1}, {1,1,1,1}, {1,1,0,0}, {1,0,0,1}};
    int *gridPtr[5];
    for (int i = 0; i < 5; i++) gridPtr[i] = (int *)grid[i];

    printf("%d\n", shortestPathBinaryMaze(5, 4, gridPtr, 0, 1, 2, 2));
    return 0;
}
