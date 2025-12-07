#include <stdio.h>

void spiralMatrix(int rows, int cols, int **matrixData, int *resultArr) {
    int topRow = 0, bottomRow = rows - 1;
    int leftCol = 0, rightCol = cols - 1;
    int resultIdx = 0;

    while (topRow <= bottomRow && leftCol <= rightCol) {
        for (int c = leftCol; c <= rightCol; c++) {
            resultArr[resultIdx++] = matrixData[topRow][c];
        }
        topRow++;

        for (int r = topRow; r <= bottomRow; r++) {
            resultArr[resultIdx++] = matrixData[r][rightCol];
        }
        rightCol--;

        if (topRow <= bottomRow) {
            for (int c = rightCol; c >= leftCol; c--) {
                resultArr[resultIdx++] = matrixData[bottomRow][c];
            }
            bottomRow--;
        }

        if (leftCol <= rightCol) {
            for (int r = bottomRow; r >= topRow; r--) {
                resultArr[resultIdx++] = matrixData[r][leftCol];
            }
            leftCol++;
        }
    }
}

int main() {
    printf("Spiral traversal complete\n");
    return 0;
}
