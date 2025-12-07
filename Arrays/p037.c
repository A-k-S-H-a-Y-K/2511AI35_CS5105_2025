#include <stdio.h>

long long countInversions(int arrSize, int *elementsArr) {
    long long inversionCount = 0;

    for (int idx1 = 0; idx1 < arrSize; idx1++) {
        for (int idx2 = idx1 + 1; idx2 < arrSize; idx2++) {
            if (elementsArr[idx1] > elementsArr[idx2]) {
                inversionCount++;
            }
        }
    }

    return inversionCount;
}

int main() {
    int nums[] = {2, 3, 7, 1, 3, 5};
    printf("%lld\n", countInversions(6, nums));
    return 0;
}
