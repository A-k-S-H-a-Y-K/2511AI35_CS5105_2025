#include <stdio.h>
#include <string.h>

void surroundedRegionsDFS(int r, int c, int rows, int cols, int **matrixData) {
    if (r < 0 || r >= rows || c < 0 || c >= cols || matrixData[r][c] != 'O') return;

    matrixData[r][c] = '#';
    surroundedRegionsDFS(r + 1, c, rows, cols, matrixData);
    surroundedRegionsDFS(r - 1, c, rows, cols, matrixData);
    surroundedRegionsDFS(r, c + 1, rows, cols, matrixData);
    surroundedRegionsDFS(r, c - 1, rows, cols, matrixData);
}

void surroundedRegions(int rows, int cols, char **matrixData) {
    for (int r = 0; r < rows; r++) {
        if (matrixData[r][0] == 'O') surroundedRegionsDFS(r, 0, rows, cols, (int **)matrixData);
        if (matrixData[r][cols - 1] == 'O') surroundedRegionsDFS(r, cols - 1, rows, cols, (int **)matrixData);
    }

    for (int c = 0; c < cols; c++) {
        if (matrixData[0][c] == 'O') surroundedRegionsDFS(0, c, rows, cols, (int **)matrixData);
        if (matrixData[rows - 1][c] == 'O') surroundedRegionsDFS(rows - 1, c, rows, cols, (int **)matrixData);
    }

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (matrixData[r][c] == '#') matrixData[r][c] = 'O';
            else if (matrixData[r][c] == 'O') matrixData[r][c] = 'X';
        }
    }
}

int main() {
    printf("Surrounded regions processed\n");
    return 0;
}
