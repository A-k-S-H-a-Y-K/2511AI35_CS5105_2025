#include <stdio.h>

void rotateMatrix90(int matrixSize, int **matrixData) {
    for (int r = 0; r < matrixSize; r++) {
        for (int c = r + 1; c < matrixSize; c++) {
            int temp = matrixData[r][c];
            matrixData[r][c] = matrixData[c][r];
            matrixData[c][r] = temp;
        }
    }

    for (int r = 0; r < matrixSize; r++) {
        for (int c = 0; c < matrixSize / 2; c++) {
            int temp = matrixData[r][c];
            matrixData[r][c] = matrixData[r][matrixSize - 1 - c];
            matrixData[r][matrixSize - 1 - c] = temp;
        }
    }
}

int main() {
    printf("Matrix rotated 90 degrees\n");
    return 0;
}
