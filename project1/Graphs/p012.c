#include <stdio.h>
#include <string.h>

void dfsTraversal(int currNode, int **adjMatrix, int vertexCount, int *visited, int *resultArr, int *resultIdx) {
    visited[currNode] = 1;
    resultArr[(*resultIdx)++] = currNode;

    for (int neighborIdx = 0; neighborIdx < vertexCount; neighborIdx++) {
        if (adjMatrix[currNode][neighborIdx] && !visited[neighborIdx]) {
            dfsTraversal(neighborIdx, adjMatrix, vertexCount, visited, resultArr, resultIdx);
        }
    }
}

void dfs(int vertexCount, int **adjMatrix, int *resultArr) {
    int visited[vertexCount];
    memset(visited, 0, sizeof(visited));
    int resultIdx = 0;

    for (int nodeIdx = 0; nodeIdx < vertexCount; nodeIdx++) {
        if (!visited[nodeIdx]) {
            dfsTraversal(nodeIdx, adjMatrix, vertexCount, visited, resultArr, &resultIdx);
        }
    }
}

int main() {
    int adj[5][5] = {{0,1,0,1,1}, {1,0,1,0,0}, {0,1,0,0,0}, {1,0,0,0,1}, {1,0,0,1,0}};
    int *adjPtr[5];
    for (int i = 0; i < 5; i++) adjPtr[i] = (int *)adj[i];

    int result[5];
    dfs(5, adjPtr, result);
    for (int i = 0; i < 5; i++) printf("%d ", result[i]);
    printf("\n");
    return 0;
}
