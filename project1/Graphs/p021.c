#include <stdio.h>
#include <string.h>

int detectCycleDirectedDFS(int currNode, int *visitState, int **adjMatrix, int vertexCount) {
    visitState[currNode] = 1;

    for (int neighborIdx = 0; neighborIdx < vertexCount; neighborIdx++) {
        if (adjMatrix[currNode][neighborIdx]) {
            if (visitState[neighborIdx] == 0) {
                if (detectCycleDirectedDFS(neighborIdx, visitState, adjMatrix, vertexCount)) return 1;
            } else if (visitState[neighborIdx] == 1) {
                return 1;
            }
        }
    }

    visitState[currNode] = 2;
    return 0;
}

int detectCycleDirected(int vertexCount, int **adjMatrix) {
    int visitState[vertexCount];
    memset(visitState, 0, sizeof(visitState));

    for (int nodeIdx = 0; nodeIdx < vertexCount; nodeIdx++) {
        if (visitState[nodeIdx] == 0) {
            if (detectCycleDirectedDFS(nodeIdx, visitState, adjMatrix, vertexCount)) return 1;
        }
    }
    return 0;
}

int main() {
    int adj[10][10] = {{0}};
    int *adjPtr[10];
    for (int i = 0; i < 10; i++) adjPtr[i] = (int *)adj[i];

    printf("%d\n", detectCycleDirected(10, adjPtr));
    return 0;
}
