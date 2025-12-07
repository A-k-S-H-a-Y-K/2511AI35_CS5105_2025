#include <stdio.h>
#include <stdlib.h>

int countQuadruplets(int arrSize, int *elementsArr, int targetSum) {
    qsort(elementsArr, arrSize, sizeof(int), (int (*)(const void *, const void *))memcmp);

    int quadrupletCount = 0;

    for (int idx1 = 0; idx1 < arrSize - 3; idx1++) {
        for (int idx2 = idx1 + 1; idx2 < arrSize - 2; idx2++) {
            int leftPtr = idx2 + 1, rightPtr = arrSize - 1;

            while (leftPtr < rightPtr) {
                int currSum = elementsArr[idx1] + elementsArr[idx2] + elementsArr[leftPtr] + elementsArr[rightPtr];

                if (currSum == targetSum) {
                    quadrupletCount++;
                    leftPtr++;
                    rightPtr--;
                } else if (currSum < targetSum) {
                    leftPtr++;
                } else {
                    rightPtr--;
                }
            }
        }
    }

    return quadrupletCount;
}

int main() {
    int nums[] = {1, -2, 3, 5, 7, 9};
    printf("%d\n", countQuadruplets(6, nums, 7));
    return 0;
}
