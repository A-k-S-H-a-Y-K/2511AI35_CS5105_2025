#include <stdio.h>
#include <string.h>

void articulationPointDFS(int currNode, int parentNode, int *discoveryTime, int *lowTime, int *visited, int *isArticulation, int **adjMatrix, int vertexCount, int *timeCounter) {
    int childrenCount = 0;
    visited[currNode] = 1;
    discoveryTime[currNode] = lowTime[currNode] = (*timeCounter)++;

    for (int neighborIdx = 0; neighborIdx < vertexCount; neighborIdx++) {
        if (adjMatrix[currNode][neighborIdx]) {
            if (!visited[neighborIdx]) {
                childrenCount++;
                articulationPointDFS(neighborIdx, currNode, discoveryTime, lowTime, visited, isArticulation, adjMatrix, vertexCount, timeCounter);

                lowTime[currNode] = (lowTime[neighborIdx] < lowTime[currNode]) ? lowTime[neighborIdx] : lowTime[currNode];

                if (parentNode == -1 && childrenCount > 1) {
                    isArticulation[currNode] = 1;
                } else if (parentNode != -1 && lowTime[neighborIdx] >= discoveryTime[currNode]) {
                    isArticulation[currNode] = 1;
                }
            } else if (neighborIdx != parentNode) {
                lowTime[currNode] = (discoveryTime[neighborIdx] < lowTime[currNode]) ? discoveryTime[neighborIdx] : lowTime[currNode];
            }
        }
    }
}

int main() {
    printf("Articulation Points in Graph\n");
    return 0;
}
