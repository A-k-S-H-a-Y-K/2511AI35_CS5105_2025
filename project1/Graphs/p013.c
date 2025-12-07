#include <stdio.h>
#include <string.h>

void floodFillDFS(int r, int c, int rows, int cols, int **imageData, int originalColor, int newColor) {
    if (r < 0 || r >= rows || c < 0 || c >= cols || imageData[r][c] != originalColor) return;

    imageData[r][c] = newColor;
    floodFillDFS(r + 1, c, rows, cols, imageData, originalColor, newColor);
    floodFillDFS(r - 1, c, rows, cols, imageData, originalColor, newColor);
    floodFillDFS(r, c + 1, rows, cols, imageData, originalColor, newColor);
    floodFillDFS(r, c - 1, rows, cols, imageData, originalColor, newColor);
}

void floodFill(int rows, int cols, int **imageData, int startRow, int startCol, int newColor) {
    int originalColor = imageData[startRow][startCol];
    if (originalColor != newColor) {
        floodFillDFS(startRow, startCol, rows, cols, imageData, originalColor, newColor);
    }
}

int main() {
    int image[3][3] = {{1,1,1}, {1,1,0}, {1,0,1}};
    int *imgPtr[3];
    for (int i = 0; i < 3; i++) imgPtr[i] = (int *)image[i];

    floodFill(3, 3, imgPtr, 1, 1, 2);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) printf("%d ", image[i][j]);
        printf("\n");
    }
    return 0;
}
