#include <stdio.h>

int findMissingNumber(int arrSize, int *elementsArr) {
    long long expectedSum = ((long long)arrSize * (arrSize + 1)) / 2;
    long long actualSum = 0;

    for (int idx = 0; idx < arrSize; idx++) {
        actualSum += elementsArr[idx];
    }

    return (int)(expectedSum - actualSum);
}

int main() {
    int nums[] = {0, 2, 3, 1, 4};
    printf("%d\n", findMissingNumber(5, nums));
    return 0;
}
