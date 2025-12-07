#include <stdio.h>

int maxConsecutiveOnes(int arrSize, int *elementsArr) {
    int maxCount = 0, currCount = 0;

    for (int idx = 0; idx < arrSize; idx++) {
        if (elementsArr[idx] == 1) {
            currCount++;
            maxCount = (currCount > maxCount) ? currCount : maxCount;
        } else {
            currCount = 0;
        }
    }

    return maxCount;
}

int main() {
    int nums[] = {1, 1, 0, 0, 1, 1, 1, 0};
    printf("%d\n", maxConsecutiveOnes(8, nums));
    return 0;
}
