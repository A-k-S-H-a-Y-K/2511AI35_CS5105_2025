#include <stdio.h>
#include <stdlib.h>

void rearrangeBySign(int arrSize, int *elementsArr) {
    int positiveArr[arrSize / 2];
    int negativeArr[arrSize / 2];
    int posIdx = 0, negIdx = 0;

    for (int idx = 0; idx < arrSize; idx++) {
        if (elementsArr[idx] > 0) {
            positiveArr[posIdx++] = elementsArr[idx];
        } else {
            negativeArr[negIdx++] = elementsArr[idx];
        }
    }

    posIdx = 0;
    negIdx = 0;
    for (int idx = 0; idx < arrSize; idx += 2) {
        elementsArr[idx] = positiveArr[posIdx++];
        elementsArr[idx + 1] = negativeArr[negIdx++];
    }
}

int main() {
    int nums[] = {2, 4, 5, -1, -3, -4};
    rearrangeBySign(6, nums);
    for (int i = 0; i < 6; i++) printf("%d ", nums[i]);
    printf("\n");
    return 0;
}
