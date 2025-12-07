#include <stdio.h>

long long countReversePairs(int arrSize, int *elementsArr) {
    long long reversePairCount = 0;

    for (int idx1 = 0; idx1 < arrSize; idx1++) {
        for (int idx2 = idx1 + 1; idx2 < arrSize; idx2++) {
            if (elementsArr[idx1] > 2 * elementsArr[idx2]) {
                reversePairCount++;
            }
        }
    }

    return reversePairCount;
}

int main() {
    int nums[] = {6, 4, 1, 2, 7};
    printf("%lld\n", countReversePairs(5, nums));
    return 0;
}
