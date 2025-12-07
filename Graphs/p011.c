#include <stdio.h>
#include <string.h>

int findParent(int nodeIdx, int *parentArr) {
    if (parentArr[nodeIdx] != nodeIdx) {
        parentArr[nodeIdx] = findParent(parentArr[nodeIdx], parentArr);
    }
    return parentArr[nodeIdx];
}

void unionSets(int nodeA, int nodeB, int *parentArr) {
    int parentA = findParent(nodeA, parentArr);
    int parentB = findParent(nodeB, parentArr);
    if (parentA != parentB) {
        parentArr[parentA] = parentB;
    }
}

int removeStones(int stoneCount, int **stonesList) {
    int parentArr[20001];
    for (int i = 0; i < 20001; i++) parentArr[i] = i;

    for (int stoneIdx = 0; stoneIdx < stoneCount; stoneIdx++) {
        int rowKey = stonesList[stoneIdx][0];
        int colKey = 10000 + stonesList[stoneIdx][1];
        unionSets(rowKey, colKey, parentArr);
    }

    int componentSet[20001] = {0};
    for (int stoneIdx = 0; stoneIdx < stoneCount; stoneIdx++) {
        int rowKey = stonesList[stoneIdx][0];
        componentSet[findParent(rowKey, parentArr)]++;
    }

    int totalRemoved = 0;
    for (int i = 0; i < 20001; i++) {
        if (componentSet[i] > 0) {
            totalRemoved += componentSet[i] - 1;
        }
    }

    return totalRemoved;
}

int main() {
    int stones[6][2] = {{0,0}, {0,1}, {1,0}, {1,2}, {2,1}, {2,2}};
    int *sPtr[6];
    for (int i = 0; i < 6; i++) sPtr[i] = (int *)stones[i];

    printf("%d\n", removeStones(6, sPtr));
    return 0;
}
