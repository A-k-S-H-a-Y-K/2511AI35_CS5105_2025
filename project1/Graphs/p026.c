#include <stdio.h>
#include <string.h>

int isSafeStateDFS(int currNode, int *visitState, int **adjMatrix, int vertexCount) {
    if (visitState[currNode] == 2) return 1;
    if (visitState[currNode] == 1) return 0;

    visitState[currNode] = 1;

    for (int neighborIdx = 0; neighborIdx < vertexCount; neighborIdx++) {
        if (adjMatrix[currNode][neighborIdx]) {
            if (!isSafeStateDFS(neighborIdx, visitState, adjMatrix, vertexCount)) {
                return 0;
            }
        }
    }

    visitState[currNode] = 2;
    return 1;
}

int findSafeStates(int vertexCount, int **adjMatrix, int *resultArr) {
    int visitState[vertexCount];
    memset(visitState, 0, sizeof(visitState));
    int resultIdx = 0;

    for (int nodeIdx = 0; nodeIdx < vertexCount; nodeIdx++) {
        if (isSafeStateDFS(nodeIdx, visitState, adjMatrix, vertexCount)) {
            resultArr[resultIdx++] = nodeIdx;
        }
    }

    return resultIdx;
}

int main() {
    int adj[7][7] = {{0}};
    int *adjPtr[7];
    for (int i = 0; i < 7; i++) adjPtr[i] = (int *)adj[i];

    int result[7];
    int count = findSafeStates(7, adjPtr, result);
    for (int i = 0; i < count; i++) printf("%d ", result[i]);
    printf("\n");
    return 0;
}
