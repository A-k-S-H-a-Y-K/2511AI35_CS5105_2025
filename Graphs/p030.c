#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int node, dist;
} DijkstraNode;

int compareDijkstra(const void *a, const void *b) {
    return ((DijkstraNode *)a)->dist - ((DijkstraNode *)b)->dist;
}

void dijkstraSet(int vertexCount, int **adjMatrix, int sourceNode, int *distanceArr) {
    for (int i = 0; i < vertexCount; i++) distanceArr[i] = INT_MAX;
    distanceArr[sourceNode] = 0;

    DijkstraNode pq[vertexCount * 10];
    int pqSize = 0;
    pq[pqSize].node = sourceNode;
    pq[pqSize].dist = 0;
    pqSize++;

    int visited[vertexCount];
    memset(visited, 0, sizeof(visited));

    while (pqSize > 0) {
        qsort(pq, pqSize, sizeof(DijkstraNode), compareDijkstra);
        DijkstraNode curr = pq[0];
        for (int i = 0; i < pqSize - 1; i++) pq[i] = pq[i + 1];
        pqSize--;

        if (visited[curr.node]) continue;
        visited[curr.node] = 1;

        for (int neighborIdx = 0; neighborIdx < vertexCount; neighborIdx++) {
            if (adjMatrix[curr.node][neighborIdx] && !visited[neighborIdx]) {
                if (distanceArr[curr.node] + adjMatrix[curr.node][neighborIdx] < distanceArr[neighborIdx]) {
                    distanceArr[neighborIdx] = distanceArr[curr.node] + adjMatrix[curr.node][neighborIdx];
                    pq[pqSize].node = neighborIdx;
                    pq[pqSize].dist = distanceArr[neighborIdx];
                    pqSize++;
                }
            }
        }
    }
}

int main() {
    printf("Dijkstra Using Set\n");
    return 0;
}
