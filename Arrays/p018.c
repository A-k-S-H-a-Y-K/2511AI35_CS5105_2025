#include <stdio.h>

int findSingleNumber(int arrSize, int *elementsArr) {
    int resultXor = 0;
    for (int idx = 0; idx < arrSize; idx++) {
        resultXor ^= elementsArr[idx];
    }
    return resultXor;
}

int main() {
    int nums[] = {1, 2, 2, 4, 3, 1, 4};
    printf("%d\n", findSingleNumber(7, nums));
    return 0;
}
