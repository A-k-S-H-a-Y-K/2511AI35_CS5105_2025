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

int main() {
    printf("Accounts Merge - DSU\n");
    return 0;
}
