#include <stdio.h>

int removeDuplicates(int arrSize, int *elementsArr) {
    if (arrSize == 0) return 0;

    int uniquePtr = 0;
    for (int idx = 1; idx < arrSize; idx++) {
        if (elementsArr[idx] != elementsArr[uniquePtr]) {
            uniquePtr++;
            elementsArr[uniquePtr] = elementsArr[idx];
        }
    }
    return uniquePtr + 1;
}

int main() {
    int nums[] = {0, 0, 3, 3, 5, 6};
    printf("%d\n", removeDuplicates(6, nums));
    return 0;
}
