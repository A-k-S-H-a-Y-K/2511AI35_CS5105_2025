#include <stdio.h>
#include <string.h>

int isBipartite(int vertexCount, int **adjList, int *adjSize) {
    int colorMap[vertexCount];
    memset(colorMap, -1, sizeof(colorMap));

    for (int startNode = 0; startNode < vertexCount; startNode++) {
        if (colorMap[startNode] == -1) {
            int stack[vertexCount];
            int stackTop = 0;
            stack[stackTop++] = startNode;
            colorMap[startNode] = 0;

            while (stackTop > 0) {
                int currNode = stack[--stackTop];

                for (int neighborIdx = 0; neighborIdx < adjSize[currNode]; neighborIdx++) {
                    int neighbor = adjList[currNode][neighborIdx];

                    if (colorMap[neighbor] == -1) {
                        colorMap[neighbor] = 1 - colorMap[currNode];
                        stack[stackTop++] = neighbor;
                    } else if (colorMap[neighbor] == colorMap[currNode]) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

int main() {
    int adj[3][2] = {{1,0}, {0,2}, {1}};
    int adjSz[3] = {2, 2, 1};
    int *adjPtr[3];
    for (int i = 0; i < 3; i++) adjPtr[i] = (int *)adj[i];

    printf("%d\n", isBipartite(3, adjPtr, adjSz));
    return 0;
}
