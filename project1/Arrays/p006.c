#include <stdio.h>

void moveZerosToEnd(int arrSize, int *elementsArr) {
    int nonZeroPtr = 0;

    for (int idx = 0; idx < arrSize; idx++) {
        if (elementsArr[idx] != 0) {
            elementsArr[nonZeroPtr] = elementsArr[idx];
            nonZeroPtr++;
        }
    }

    for (int idx = nonZeroPtr; idx < arrSize; idx++) {
        elementsArr[idx] = 0;
    }
}

int main() {
    int nums[] = {0, 1, 4, 0, 5, 2};
    moveZerosToEnd(6, nums);
    for (int i = 0; i < 6; i++) printf("%d ", nums[i]);
    printf("\n");
    return 0;
}
