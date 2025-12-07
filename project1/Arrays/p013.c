#include <stdio.h>
#include <stdlib.h>

int compareIntegers(const void *aPtr, const void *bPtr) {
    return (*(int *)aPtr - *(int *)bPtr);
}

int findArrayLeaders(int arrSize, int *elementsArr, int *leaderArr) {
    int rightMax = elementsArr[arrSize - 1];
    leaderArr[0] = rightMax;
    int leaderIdx = 1;

    for (int idx = arrSize - 2; idx >= 0; idx--) {
        if (elementsArr[idx] > rightMax) {
            leaderArr[leaderIdx++] = elementsArr[idx];
            rightMax = elementsArr[idx];
        }
    }

    qsort(leaderArr, leaderIdx, sizeof(int), compareIntegers);
    return leaderIdx;
}

int main() {
    int nums[] = {1, 2, 5, 3, 1, 2};
    int leaders[6];
    int count = findArrayLeaders(6, nums, leaders);
    for (int i = 0; i < count; i++) printf("%d ", leaders[i]);
    printf("\n");
    return 0;
}
