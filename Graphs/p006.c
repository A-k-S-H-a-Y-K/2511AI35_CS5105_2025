#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int node, dist;
} MinHeapNode;

int compareMinHeap(const void *a, const void *b) {
    return ((MinHeapNode *)a)->dist - ((MinHeapNode *)b)->dist;
}

void dijkstraShortestPath(int vertexCount, int **adjList, int sourceNode, int *distanceArr) {
    for (int i = 0; i < vertexCount; i++) distanceArr[i] = INT_MAX;
    distanceArr[sourceNode] = 0;

    MinHeapNode pq[vertexCount * vertexCount];
    int pqSize = 0;
    pq[pqSize].node = sourceNode;
    pq[pqSize].dist = 0;
    pqSize++;

    int visited[vertexCount];
    memset(visited, 0, sizeof(visited));

    while (pqSize > 0) {
        qsort(pq, pqSize, sizeof(MinHeapNode), compareMinHeap);
        MinHeapNode curr = pq[0];
        for (int i = 0; i < pqSize - 1; i++) pq[i] = pq[i + 1];
        pqSize--;

        if (visited[curr.node]) continue;
        visited[curr.node] = 1;

        for (int neighborIdx = 0; adjList[curr.node][neighborIdx * 2] != -1; neighborIdx++) {
            int neighbor = adjList[curr.node][neighborIdx * 2];
            int weight = adjList[curr.node][neighborIdx * 2 + 1];

            if (!visited[neighbor] && distanceArr[curr.node] + weight < distanceArr[neighbor]) {
                distanceArr[neighbor] = distanceArr[curr.node] + weight;
                pq[pqSize].node = neighbor;
                pq[pqSize].dist = distanceArr[neighbor];
                pqSize++;
            }
        }
    }
}

int main() {
    int adj[3][5] = {{1, 1, 2, 6, -1}, {2, 3, 0, 1, -1}, {1, 3, 0, 6, -1}};
    int *adjPtr[3];
    for (int i = 0; i < 3; i++) adjPtr[i] = (int *)adj[i];

    int dist[3];
    dijkstraShortestPath(3, adjPtr, 2, dist);
    for (int i = 0; i < 3; i++) printf("%d ", dist[i]);
    printf("\n");
    return 0;
}
