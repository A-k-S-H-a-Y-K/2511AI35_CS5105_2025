#include <stdio.h>
#include <string.h>

#define INF 1e9

void bellmanFord(int vertexCount, int **edgesList, int edgeCount, int sourceNode, int *distanceArr) {
    for (int i = 0; i < vertexCount; i++) distanceArr[i] = INF;
    distanceArr[sourceNode] = 0;

    for (int i = 0; i < vertexCount - 1; i++) {
        for (int edgeIdx = 0; edgeIdx < edgeCount; edgeIdx++) {
            int u = edgesList[edgeIdx][0];
            int v = edgesList[edgeIdx][1];
            int w = edgesList[edgeIdx][2];

            if (distanceArr[u] != INF && distanceArr[u] + w < distanceArr[v]) {
                distanceArr[v] = distanceArr[u] + w;
            }
        }
    }

    for (int edgeIdx = 0; edgeIdx < edgeCount; edgeIdx++) {
        int u = edgesList[edgeIdx][0];
        int v = edgesList[edgeIdx][1];
        int w = edgesList[edgeIdx][2];

        if (distanceArr[u] != INF && distanceArr[u] + w < distanceArr[v]) {
            for (int i = 0; i < vertexCount; i++) distanceArr[i] = -INF;
            return;
        }
    }
}

int main() {
    printf("Bellman Ford Algorithm\n");
    return 0;
}
