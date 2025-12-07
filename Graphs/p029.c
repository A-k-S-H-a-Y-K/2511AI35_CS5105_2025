#include <stdio.h>
#include <string.h>

void topoSortDAG(int currNode, int **adjMatrix, int vertexCount, int *visited, int *stack, int *stackTop) {
    visited[currNode] = 1;

    for (int neighborIdx = 0; neighborIdx < vertexCount; neighborIdx++) {
        if (adjMatrix[currNode][neighborIdx] && !visited[neighborIdx]) {
            topoSortDAG(neighborIdx, adjMatrix, vertexCount, visited, stack, stackTop);
        }
    }

    stack[(*stackTop)++] = currNode;
}

void shortestPathDAG(int vertexCount, int **edgesList, int edgeCount, int *distanceArr) {
    for (int i = 0; i < vertexCount; i++) distanceArr[i] = INT_MAX;
    distanceArr[0] = 0;

    int visited[vertexCount];
    memset(visited, 0, sizeof(visited));
    int stack[vertexCount];
    int stackTop = 0;

    for (int nodeIdx = 0; nodeIdx < vertexCount; nodeIdx++) {
        if (!visited[nodeIdx]) {
            topoSortDAG(nodeIdx, (int **)edgesList, vertexCount, visited, stack, &stackTop);
        }
    }

    while (stackTop > 0) {
        int u = stack[--stackTop];

        for (int edgeIdx = 0; edgeIdx < edgeCount; edgeIdx++) {
            if (edgesList[edgeIdx][0] == u && distanceArr[u] != INT_MAX) {
                int v = edgesList[edgeIdx][1];
                int w = edgesList[edgeIdx][2];
                if (distanceArr[u] + w < distanceArr[v]) {
                    distanceArr[v] = distanceArr[u] + w;
                }
            }
        }
    }
}

int main() {
    printf("Shortest Path in DAG\n");
    return 0;
}
