#include <stdio.h>
#include <string.h>

typedef struct { int node, parent; } QueueItem;

int detectCycleBFS(int vertexCount, int **adjMatrix) {
    int visited[vertexCount];
    memset(visited, 0, sizeof(visited));

    for (int startNode = 0; startNode < vertexCount; startNode++) {
        if (!visited[startNode]) {
            QueueItem queue[vertexCount];
            int qIdx = 0, fIdx = 0;

            queue[qIdx].node = startNode;
            queue[qIdx].parent = -1;
            qIdx++;
            visited[startNode] = 1;

            while (fIdx < qIdx) {
                QueueItem curr = queue[fIdx++];

                for (int neighborIdx = 0; neighborIdx < vertexCount; neighborIdx++) {
                    if (adjMatrix[curr.node][neighborIdx] && !visited[neighborIdx]) {
                        visited[neighborIdx] = 1;
                        queue[qIdx].node = neighborIdx;
                        queue[qIdx].parent = curr.node;
                        qIdx++;
                    } else if (adjMatrix[curr.node][neighborIdx] && neighborIdx != curr.parent) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int main() {
    int adj[8][8] = {{0}};
    adj[0][1] = adj[1][0] = 1;
    adj[1][2] = adj[2][1] = 1;
    int *adjPtr[8];
    for (int i = 0; i < 8; i++) adjPtr[i] = (int *)adj[i];

    printf("%d\n", detectCycleBFS(8, adjPtr));
    return 0;
}
