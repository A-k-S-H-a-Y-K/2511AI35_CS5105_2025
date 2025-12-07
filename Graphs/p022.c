#include <stdio.h>
#include <string.h>

void topoSortDFS(int currNode, int **adjMatrix, int vertexCount, int *visited, int *stack, int *stackTop) {
    visited[currNode] = 1;

    for (int neighborIdx = 0; neighborIdx < vertexCount; neighborIdx++) {
        if (adjMatrix[currNode][neighborIdx] && !visited[neighborIdx]) {
            topoSortDFS(neighborIdx, adjMatrix, vertexCount, visited, stack, stackTop);
        }
    }

    stack[(*stackTop)++] = currNode;
}

void topologicalSort(int vertexCount, int **adjMatrix, int *resultArr) {
    int visited[vertexCount];
    memset(visited, 0, sizeof(visited));
    int stack[vertexCount];
    int stackTop = 0;

    for (int nodeIdx = 0; nodeIdx < vertexCount; nodeIdx++) {
        if (!visited[nodeIdx]) {
            topoSortDFS(nodeIdx, adjMatrix, vertexCount, visited, stack, &stackTop);
        }
    }

    for (int i = 0; i < vertexCount; i++) {
        resultArr[i] = stack[vertexCount - 1 - i];
    }
}

int main() {
    int adj[6][6] = {{0}};
    int *adjPtr[6];
    for (int i = 0; i < 6; i++) adjPtr[i] = (int *)adj[i];

    int result[6];
    topologicalSort(6, adjPtr, result);
    for (int i = 0; i < 6; i++) printf("%d ", result[i]);
    printf("\n");
    return 0;
}
