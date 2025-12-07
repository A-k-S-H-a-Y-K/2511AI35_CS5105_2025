#include <stdio.h>

int findMaxElement(int arrSize, int *elementsArr) {
    int maxVal = elementsArr[0];
    for (int idx = 1; idx < arrSize; idx++) {
        if (elementsArr[idx] > maxVal) maxVal = elementsArr[idx];
    }
    return maxVal;
}

int main() {
    int nums[] = {2, 5, 1, 3, 0};
    printf("%d\n", findMaxElement(5, nums));
    return 0;
}
