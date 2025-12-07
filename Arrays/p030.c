#include <stdio.h>
#include <stdlib.h>

int countTripletSum(int arrSize, int *elementsArr, int targetSum) {
    qsort(elementsArr, arrSize, sizeof(int), (int (*)(const void *, const void *))memcmp);

    int tripletCount = 0;

    for (int idx = 0; idx < arrSize - 2; idx++) {
        int leftPtr = idx + 1, rightPtr = arrSize - 1;

        while (leftPtr < rightPtr) {
            int currSum = elementsArr[idx] + elementsArr[leftPtr] + elementsArr[rightPtr];

            if (currSum == targetSum) {
                tripletCount++;
                leftPtr++;
                rightPtr--;
                while (leftPtr < rightPtr && elementsArr[leftPtr] == elementsArr[leftPtr - 1]) leftPtr++;
                while (leftPtr < rightPtr && elementsArr[rightPtr] == elementsArr[rightPtr + 1]) rightPtr--;
            } else if (currSum < targetSum) {
                leftPtr++;
            } else {
                rightPtr--;
            }
        }
    }

    return tripletCount;
}

int main() {
    int nums[] = {2, -2, 0, 3, -3, 5};
    printf("%d\n", countTripletSum(6, nums, 0));
    return 0;
}
