#include <stdio.h>
#include <string.h>

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

int minimumOperations(int nodeCount, int **edgesList, int edgeCount) {
    int parentArr[nodeCount];
    int rankArr[nodeCount];

    for (int i = 0; i < nodeCount; i++) {
        parentArr[i] = i;
        rankArr[i] = 0;
    }

    int redundantEdges = 0;

    for (int edgeIdx = 0; edgeIdx < edgeCount; edgeIdx++) {
        int u = edgesList[edgeIdx][0];
        int v = edgesList[edgeIdx][1];

        if (findParent(u, parentArr) == findParent(v, parentArr)) {
            redundantEdges++;
        } else {
            unionSets(u, v, parentArr, rankArr);
        }
    }

    int componentsCnt = 0;
    for (int i = 0; i < nodeCount; i++) {
        if (findParent(i, parentArr) == i) {
            componentsCnt++;
        }
    }

    return (componentsCnt - 1 > redundantEdges) ? -1 : (componentsCnt - 1);
}

int main() {
    int edges[3][2] = {{0,1}, {0,2}, {1,2}};
    int *edPtr[3];
    for (int i = 0; i < 3; i++) edPtr[i] = (int *)edges[i];

    printf("%d\n", minimumOperations(4, edPtr, 3));
    return 0;
}
