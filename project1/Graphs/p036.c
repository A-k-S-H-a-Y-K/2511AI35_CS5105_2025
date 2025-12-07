#include <stdio.h>
#include <string.h>

typedef struct { int node, weight; } PrimNode;

int primsAlgorithm(int vertexCount, int **edgesList, int edgeCount) {
    int visited[vertexCount];
    memset(visited, 0, sizeof(visited));
    int mstCost = 0;
    visited[0] = 1;

    int edgeCount_used = 0;

    while (edgeCount_used < vertexCount - 1) {
        int minWeight = INT_MAX, u = -1, v = -1;

        for (int edgeIdx = 0; edgeIdx < edgeCount; edgeIdx++) {
            int a = edgesList[edgeIdx][0];
            int b = edgesList[edgeIdx][1];
            int w = edgesList[edgeIdx][2];

            if ((visited[a] && !visited[b]) || (visited[b] && !visited[a])) {
                if (w < minWeight) {
                    minWeight = w;
                    u = (visited[a]) ? a : b;
                    v = (visited[a]) ? b : a;
                }
            }
        }

        if (u == -1) break;

        visited[v] = 1;
        mstCost += minWeight;
        edgeCount_used++;
    }

    return mstCost;
}

int main() {
    printf("Prim's Algorithm MST\n");
    return 0;
}
