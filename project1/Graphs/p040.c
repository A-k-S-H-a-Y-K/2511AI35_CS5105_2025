#include <stdio.h>
#include <string.h>

int findParent(int nodeIdx, int *parentArr) {
    if (parentArr[nodeIdx] != nodeIdx) {
        parentArr[nodeIdx] = findParent(parentArr[nodeIdx], parentArr);
    }
    return parentArr[nodeIdx];
}

void unionSets(int nodeA, int nodeB, int *parentArr, int *sizeArr) {
    int parentA = findParent(nodeA, parentArr);
    int parentB = findParent(nodeB, parentArr);

    if (parentA != parentB) {
        if (sizeArr[parentA] < sizeArr[parentB]) {
            parentArr[parentA] = parentB;
            sizeArr[parentB] += sizeArr[parentA];
        } else {
            parentArr[parentB] = parentA;
            sizeArr[parentA] += sizeArr[parentB];
        }
    }
}

int largestIsland(int gridSize, int **gridData) {
    int parentArr[gridSize * gridSize];
    int sizeArr[gridSize * gridSize];

    for (int i = 0; i < gridSize * gridSize; i++) {
        parentArr[i] = i;
        sizeArr[i] = 1;
    }

    int dirs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    for (int r = 0; r < gridSize; r++) {
        for (int c = 0; c < gridSize; c++) {
            if (gridData[r][c] == 1) {
                for (int d = 0; d < 4; d++) {
                    int nr = r + dirs[d][0];
                    int nc = c + dirs[d][1];

                    if (nr >= 0 && nr < gridSize && nc >= 0 && nc < gridSize && gridData[nr][nc] == 1) {
                        unionSets(r * gridSize + c, nr * gridSize + nc, parentArr, sizeArr);
                    }
                }
            }
        }
    }

    int maxIslandSize = 0;

    for (int r = 0; r < gridSize; r++) {
        for (int c = 0; c < gridSize; c++) {
            if (gridData[r][c] == 0) {
                int connectedSize = 1;
                int visitedSet[gridSize * gridSize];
                memset(visitedSet, 0, sizeof(visitedSet));

                for (int d = 0; d < 4; d++) {
                    int nr = r + dirs[d][0];
                    int nc = c + dirs[d][1];

                    if (nr >= 0 && nr < gridSize && nc >= 0 && nc < gridSize && gridData[nr][nc] == 1) {
                        int parentNode = findParent(nr * gridSize + nc, parentArr);
                        if (!visitedSet[parentNode]) {
                            visitedSet[parentNode] = 1;
                            connectedSize += sizeArr[parentNode];
                        }
                    }
                }

                maxIslandSize = (connectedSize > maxIslandSize) ? connectedSize : maxIslandSize;
            }
        }
    }

    return maxIslandSize;
}

int main() {
    printf("Making a Large Island\n");
    return 0;
}
