#include <stdio.h>
#include <string.h>

#define INF 1e9

void floydWarshall(int vertexCount, int **matrixData) {
    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++) {
            if (matrixData[i][j] == -1 && i != j) {
                matrixData[i][j] = INF;
            }
        }
    }

    for (int k = 0; k < vertexCount; k++) {
        for (int i = 0; i < vertexCount; i++) {
            for (int j = 0; j < vertexCount; j++) {
                if (matrixData[i][k] + matrixData[k][j] < matrixData[i][j]) {
                    matrixData[i][j] = matrixData[i][k] + matrixData[k][j];
                }
            }
        }
    }

    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++) {
            if (matrixData[i][j] == INF) {
                matrixData[i][j] = -1;
            }
        }
    }
}

int main() {
    printf("Floyd Warshall Algorithm\n");
    return 0;
}
