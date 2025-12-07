#include <stdio.h>
#include <stdlib.h>

int findLongestConsecutive(int arrSize, int *elementsArr) {
    if (arrSize == 0) return 0;

    qsort(elementsArr, arrSize, sizeof(int), (int (*)(const void *, const void *))memcmp);

    int maxLen = 1, currLen = 1;

    for (int idx = 1; idx < arrSize; idx++) {
        if (elementsArr[idx] == elementsArr[idx - 1] + 1) {
            currLen++;
        } else if (elementsArr[idx] != elementsArr[idx - 1]) {
            currLen = 1;
        }
        maxLen = (currLen > maxLen) ? currLen : maxLen;
    }

    return maxLen;
}

int main() {
    int nums[] = {100, 4, 200, 1, 3, 2};
    printf("%d\n", findLongestConsecutive(6, nums));
    return 0;
}
