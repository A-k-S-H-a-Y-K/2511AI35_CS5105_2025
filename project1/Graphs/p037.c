#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int findParent(int nodeIdx, int *parentArr) {
    if (parentArr[nodeIdx] != nodeIdx) {
        parentArr[nodeIdx] = findParent(parentArr[nodeIdx], parentArr);
    }
    return parentArr[nodeIdx];
}

void unionSets(int nodeA, int nodeB, int *parentArr, int *rankArr) {
    int parentA = findParent(nodeA, parentArr);
    int parentB = findParent(nodeB, parentArr);

    if (parentA != parentB) {
        if (rankArr[parentA] < rankArr[parentB]) {
            parentArr[parentA] = parentB;
        } else if (rankArr[parentA] > rankArr[parentB]) {
            parentArr[parentB] = parentA;
        } else {
            parentArr[parentB] = parentA;
            rankArr[parentA]++;
        }
    }
}

int compareEdges(const void *a, const void *b) {
    return ((int *)a)[2] - ((int *)b)[2];
}

int kruskalsAlgorithm(int vertexCount, int **edgesList, int edgeCount) {
    qsort(*edgesList, edgeCount, sizeof(int) * 3, compareEdges);

    int parentArr[vertexCount];
    int rankArr[vertexCount];

    for (int i = 0; i < vertexCount; i++) {
        parentArr[i] = i;
        rankArr[i] = 0;
    }

    int mstCost = 0, edgesUsed = 0;

    for (int edgeIdx = 0; edgeIdx < edgeCount && edgesUsed < vertexCount - 1; edgeIdx++) {
        int u = edgesList[edgeIdx][0];
        int v = edgesList[edgeIdx][1];
        int w = edgesList[edgeIdx][2];

        if (findParent(u, parentArr) != findParent(v, parentArr)) {
            unionSets(u, v, parentArr, rankArr);
            mstCost += w;
            edgesUsed++;
        }
    }

    return mstCost;
}

int main() {
    printf("Kruskal's Algorithm MST\n");
    return 0;
}
