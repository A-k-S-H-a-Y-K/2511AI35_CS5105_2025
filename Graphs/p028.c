#include <stdio.h>
#include <string.h>

typedef struct { int node, dist; } DistNode;

void shortestPathUnit(int vertexCount, int **adjMatrix, int sourceNode, int *distanceArr) {
    DistNode queue[vertexCount];
    int qIdx = 0, fIdx = 0;

    for (int i = 0; i < vertexCount; i++) distanceArr[i] = -1;

    queue[qIdx].node = sourceNode;
    queue[qIdx].dist = 0;
    qIdx++;
    distanceArr[sourceNode] = 0;

    while (fIdx < qIdx) {
        DistNode curr = queue[fIdx++];

        for (int neighborIdx = 0; neighborIdx < vertexCount; neighborIdx++) {
            if (adjMatrix[curr.node][neighborIdx] && distanceArr[neighborIdx] == -1) {
                distanceArr[neighborIdx] = curr.dist + 1;
                queue[qIdx].node = neighborIdx;
                queue[qIdx].dist = curr.dist + 1;
                qIdx++;
            }
        }
    }
}

int main() {
    int adj[9][9] = {{0}};
    int *adjPtr[9];
    for (int i = 0; i < 9; i++) adjPtr[i] = (int *)adj[i];

    int dist[9];
    shortestPathUnit(9, adjPtr, 0, dist);
    for (int i = 0; i < 9; i++) printf("%d ", dist[i]);
    printf("\n");
    return 0;
}
