#include <stdio.h>
#include <string.h>

void sccKosarajuDFS1(int currNode, int *visited, int **adjMatrix, int vertexCount, int *stack, int *stackTop) {
    visited[currNode] = 1;

    for (int neighborIdx = 0; neighborIdx < vertexCount; neighborIdx++) {
        if (adjMatrix[currNode][neighborIdx] && !visited[neighborIdx]) {
            sccKosarajuDFS1(neighborIdx, visited, adjMatrix, vertexCount, stack, stackTop);
        }
    }

    stack[(*stackTop)++] = currNode;
}

void sccKosarajuDFS2(int currNode, int *visited, int **transposeMatrix, int vertexCount) {
    visited[currNode] = 1;

    for (int neighborIdx = 0; neighborIdx < vertexCount; neighborIdx++) {
        if (transposeMatrix[currNode][neighborIdx] && !visited[neighborIdx]) {
            sccKosarajuDFS2(neighborIdx, visited, transposeMatrix, vertexCount);
        }
    }
}

int stronglyConnectedComponents(int vertexCount, int **adjMatrix) {
    int visited[vertexCount];
    memset(visited, 0, sizeof(visited));
    int stack[vertexCount];
    int stackTop = 0;

    for (int nodeIdx = 0; nodeIdx < vertexCount; nodeIdx++) {
        if (!visited[nodeIdx]) {
            sccKosarajuDFS1(nodeIdx, visited, adjMatrix, vertexCount, stack, &stackTop);
        }
    }

    int transposeMatrix[vertexCount][vertexCount];
    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++) {
            transposeMatrix[i][j] = adjMatrix[j][i];
        }
    }

    memset(visited, 0, sizeof(visited));
    int sccCount = 0;

    while (stackTop > 0) {
        int node = stack[--stackTop];
        if (!visited[node]) {
            sccKosarajuDFS2(node, visited, (int **)transposeMatrix, vertexCount);
            sccCount++;
        }
    }

    return sccCount;
}

int main() {
    printf("Strongly Connected Components\n");
    return 0;
}
