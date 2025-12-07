#include <stdio.h>
#include <string.h>

void enclaveDFS(int r, int c, int rows, int cols, int **gridData, int *visited) {
    if (r < 0 || r >= rows || c < 0 || c >= cols || gridData[r][c] == 0 || visited[r * cols + c]) return;

    visited[r * cols + c] = 1;
    enclaveDFS(r + 1, c, rows, cols, gridData, visited);
    enclaveDFS(r - 1, c, rows, cols, gridData, visited);
    enclaveDFS(r, c + 1, rows, cols, gridData, visited);
    enclaveDFS(r, c - 1, rows, cols, gridData, visited);
}

int numEnclaves(int rows, int cols, int **gridData) {
    int visited[rows * cols];
    memset(visited, 0, sizeof(visited));

    for (int r = 0; r < rows; r++) {
        if (gridData[r][0] == 1) enclaveDFS(r, 0, rows, cols, gridData, visited);
        if (gridData[r][cols - 1] == 1) enclaveDFS(r, cols - 1, rows, cols, gridData, visited);
    }

    for (int c = 0; c < cols; c++) {
        if (gridData[0][c] == 1) enclaveDFS(0, c, rows, cols, gridData, visited);
        if (gridData[rows - 1][c] == 1) enclaveDFS(rows - 1, c, rows, cols, gridData, visited);
    }

    int enclaveCount = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (gridData[r][c] == 1 && !visited[r * cols + c]) enclaveCount++;
        }
    }

    return enclaveCount;
}

int main() {
    int grid[3][3] = {{1,0,0}, {0,0,1}, {1,0,0}};
    int *gPtr[3];
    for (int i = 0; i < 3; i++) gPtr[i] = (int *)grid[i];

    printf("%d\n", numEnclaves(3, 3, gPtr));
    return 0;
}
