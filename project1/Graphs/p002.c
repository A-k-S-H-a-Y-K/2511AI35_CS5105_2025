#include <stdio.h>
#include <string.h>

int countProvinces(int vertexCount, int **isConnected) {
    int visited[vertexCount];
    memset(visited, 0, sizeof(visited));
    int provinceCount = 0;

    for (int nodeIdx = 0; nodeIdx < vertexCount; nodeIdx++) {
        if (!visited[nodeIdx]) {
            provinceCount++;
            int stack[vertexCount];
            int stackTop = 0;
            stack[stackTop++] = nodeIdx;
            visited[nodeIdx] = 1;

            while (stackTop > 0) {
                int currNode = stack[--stackTop];
                for (int neighborIdx = 0; neighborIdx < vertexCount; neighborIdx++) {
                    if (isConnected[currNode][neighborIdx] && !visited[neighborIdx]) {
                        visited[neighborIdx] = 1;
                        stack[stackTop++] = neighborIdx;
                    }
                }
            }
        }
    }
    return provinceCount;
}

int main() {
    int matrix[3][3] = {{1,0,1}, {0,1,0}, {1,0,1}};
    int *conn[3];
    for (int i = 0; i < 3; i++) conn[i] = (int *)matrix[i];

    printf("%d\n", countProvinces(3, conn));
    return 0;
}
