#include <stdio.h>
#include <string.h>

void islandDFS(int r, int c, int rows, int cols, int **gridData, int *visited) {
    if (r < 0 || r >= rows || c < 0 || c >= cols || gridData[r][c] == 0 || visited[r * cols + c]) return;

    visited[r * cols + c] = 1;

    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            islandDFS(r + dr, c + dc, rows, cols, gridData, visited);
        }
    }
}

int numIslands(int rows, int cols, int **gridData) {
    int visited[rows * cols];
    memset(visited, 0, sizeof(visited));
    int islandCount = 0;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (gridData[r][c] == 1 && !visited[r * cols + c]) {
                islandCount++;
                islandDFS(r, c, rows, cols, gridData, visited);
            }
        }
    }

    return islandCount;
}

int main() {
    int grid[3][3] = {{1,1,0}, {1,0,1}, {0,1,1}};
    int *gPtr[3];
    for (int i = 0; i < 3; i++) gPtr[i] = (int *)grid[i];

    printf("%d\n", numIslands(3, 3, gPtr));
    return 0;
}
