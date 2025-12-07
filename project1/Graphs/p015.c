#include <stdio.h>
#include <string.h>

int detectCycleDFSUtil(int currNode, int parentNode, int **adjMatrix, int vertexCount, int *visited) {
    visited[currNode] = 1;

    for (int neighborIdx = 0; neighborIdx < vertexCount; neighborIdx++) {
        if (adjMatrix[currNode][neighborIdx]) {
            if (!visited[neighborIdx]) {
                if (detectCycleDFSUtil(neighborIdx, currNode, adjMatrix, vertexCount, visited)) return 1;
            } else if (neighborIdx != parentNode) {
                return 1;
            }
        }
    }
    return 0;
}

int detectCycleDFS(int vertexCount, int **adjMatrix) {
    int visited[vertexCount];
    memset(visited, 0, sizeof(visited));

    for (int nodeIdx = 0; nodeIdx < vertexCount; nodeIdx++) {
        if (!visited[nodeIdx]) {
            if (detectCycleDFSUtil(nodeIdx, -1, adjMatrix, vertexCount, visited)) return 1;
        }
    }
    return 0;
}

int main() {
    int adj[8][8] = {{0}};
    adj[0][1] = adj[1][0] = 1;
    int *adjPtr[8];
    for (int i = 0; i < 8; i++) adjPtr[i] = (int *)adj[i];

    printf("%d\n", detectCycleDFS(8, adjPtr));
    return 0;
}
