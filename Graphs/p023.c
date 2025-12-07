#include <stdio.h>
#include <string.h>

void kahnTopologicalSort(int vertexCount, int **adjMatrix, int *resultArr) {
    int inDegree[vertexCount];
    memset(inDegree, 0, sizeof(inDegree));

    for (int u = 0; u < vertexCount; u++) {
        for (int v = 0; v < vertexCount; v++) {
            if (adjMatrix[u][v]) inDegree[v]++;
        }
    }

    int queue[vertexCount];
    int qIdx = 0, fIdx = 0;

    for (int nodeIdx = 0; nodeIdx < vertexCount; nodeIdx++) {
        if (inDegree[nodeIdx] == 0) {
            queue[qIdx++] = nodeIdx;
        }
    }

    int resultIdx = 0;

    while (fIdx < qIdx) {
        int currNode = queue[fIdx++];
        resultArr[resultIdx++] = currNode;

        for (int neighborIdx = 0; neighborIdx < vertexCount; neighborIdx++) {
            if (adjMatrix[currNode][neighborIdx]) {
                inDegree[neighborIdx]--;
                if (inDegree[neighborIdx] == 0) {
                    queue[qIdx++] = neighborIdx;
                }
            }
        }
    }
}

int main() {
    int adj[6][6] = {{0}};
    int *adjPtr[6];
    for (int i = 0; i < 6; i++) adjPtr[i] = (int *)adj[i];

    int result[6];
    kahnTopologicalSort(6, adjPtr, result);
    for (int i = 0; i < 6; i++) printf("%d ", result[i]);
    printf("\n");
    return 0;
}
