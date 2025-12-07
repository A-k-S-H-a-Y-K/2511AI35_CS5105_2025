#include <stdio.h>

void setMatrixZeros(int rows, int cols, int **matrixData) {
    int firstRowZero = 0, firstColZero = 0;

    for (int c = 0; c < cols; c++) {
        if (matrixData[0][c] == 0) {
            firstRowZero = 1;
            break;
        }
    }

    for (int r = 0; r < rows; r++) {
        if (matrixData[r][0] == 0) {
            firstColZero = 1;
            break;
        }
    }

    for (int r = 1; r < rows; r++) {
        for (int c = 1; c < cols; c++) {
            if (matrixData[r][c] == 0) {
                matrixData[r][0] = 0;
                matrixData[0][c] = 0;
            }
        }
    }

    for (int r = 1; r < rows; r++) {
        for (int c = 1; c < cols; c++) {
            if (matrixData[r][0] == 0 || matrixData[0][c] == 0) {
                matrixData[r][c] = 0;
            }
        }
    }

    if (firstRowZero) {
        for (int c = 0; c < cols; c++) matrixData[0][c] = 0;
    }
    if (firstColZero) {
        for (int r = 0; r < rows; r++) matrixData[r][0] = 0;
    }
}

int main() {
    printf("Matrix zeroes set\n");
    return 0;
}
