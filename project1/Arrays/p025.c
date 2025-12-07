#include <stdio.h>
#include <stdlib.h>

void nextPermutation(int arrSize, int *elementsArr) {
    int pivotIdx = -1;

    for (int idx = arrSize - 2; idx >= 0; idx--) {
        if (elementsArr[idx] < elementsArr[idx + 1]) {
            pivotIdx = idx;
            break;
        }
    }

    if (pivotIdx == -1) {
        for (int i = 0, j = arrSize - 1; i < j; i++, j--) {
            int temp = elementsArr[i];
            elementsArr[i] = elementsArr[j];
            elementsArr[j] = temp;
        }
        return;
    }

    int swapIdx = -1;
    for (int idx = arrSize - 1; idx > pivotIdx; idx--) {
        if (elementsArr[idx] > elementsArr[pivotIdx]) {
            swapIdx = idx;
            break;
        }
    }

    int temp = elementsArr[pivotIdx];
    elementsArr[pivotIdx] = elementsArr[swapIdx];
    elementsArr[swapIdx] = temp;

    for (int i = pivotIdx + 1, j = arrSize - 1; i < j; i++, j--) {
        temp = elementsArr[i];
        elementsArr[i] = elementsArr[j];
        elementsArr[j] = temp;
    }
}

int main() {
    int nums[] = {1, 2, 3};
    nextPermutation(3, nums);
    for (int i = 0; i < 3; i++) printf("%d ", nums[i]);
    printf("\n");
    return 0;
}
