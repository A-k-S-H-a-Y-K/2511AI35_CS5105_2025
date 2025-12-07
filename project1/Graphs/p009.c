#include <stdio.h>
#include <string.h>

#define MOD 1000000007

int waysToArrive(int nodeCount, int **edgesList, int edgeCount) {
    int distance[nodeCount];
    long long waysCnt[nodeCount];

    for (int i = 0; i < nodeCount; i++) {
        distance[i] = INT_MAX;
        waysCnt[i] = 0;
    }
    distance[0] = 0;
    waysCnt[0] = 1;

    for (int iteration = 0; iteration < nodeCount - 1; iteration++) {
        for (int edgeIdx = 0; edgeIdx < edgeCount; edgeIdx++) {
            int u = edgesList[edgeIdx][0];
            int v = edgesList[edgeIdx][1];
            int w = edgesList[edgeIdx][2];

            if (distance[u] != INT_MAX) {
                if (distance[u] + w < distance[v]) {
                    distance[v] = distance[u] + w;
                    waysCnt[v] = waysCnt[u];
                } else if (distance[u] + w == distance[v]) {
                    waysCnt[v] = (waysCnt[v] + waysCnt[u]) % MOD;
                }
            }

            if (distance[v] != INT_MAX) {
                if (distance[v] + w < distance[u]) {
                    distance[u] = distance[v] + w;
                    waysCnt[u] = waysCnt[v];
                } else if (distance[v] + w == distance[u]) {
                    waysCnt[u] = (waysCnt[u] + waysCnt[v]) % MOD;
                }
            }
        }
    }
    return waysCnt[nodeCount - 1];
}

int main() {
    int edges[10][3] = {{0,6,7}, {0,1,2}, {1,2,3}, {1,3,3}, {6,3,3}, {3,5,1}, {6,5,1}, {2,5,1}, {0,4,5}, {4,6,2}};
    int *edPtr[10];
    for (int i = 0; i < 10; i++) edPtr[i] = (int *)edges[i];

    printf("%d\n", waysToArrive(7, edPtr, 10));
    return 0;
}
