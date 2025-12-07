#include <stdio.h>
#include <string.h>

void bridgesDFS(int currNode, int parentNode, int *discoveryTime, int *lowTime, int *visited, int **adjMatrix, int vertexCount, int *timeCounter) {
    visited[currNode] = 1;
    discoveryTime[currNode] = lowTime[currNode] = (*timeCounter)++;

    for (int neighborIdx = 0; neighborIdx < vertexCount; neighborIdx++) {
        if (adjMatrix[currNode][neighborIdx]) {
            if (!visited[neighborIdx]) {
                bridgesDFS(neighborIdx, currNode, discoveryTime, lowTime, visited, adjMatrix, vertexCount, timeCounter);
                lowTime[currNode] = (lowTime[neighborIdx] < lowTime[currNode]) ? lowTime[neighborIdx] : lowTime[currNode];
            } else if (neighborIdx != parentNode) {
                lowTime[currNode] = (discoveryTime[neighborIdx] < lowTime[currNode]) ? discoveryTime[neighborIdx] : lowTime[currNode];
            }
        }
    }
}

int main() {
    printf("Bridges in Graph - Tarjan's Algorithm\n");
    return 0;
}
