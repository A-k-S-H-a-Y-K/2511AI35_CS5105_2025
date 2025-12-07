#include <stdio.h>

int linearSearch(int arrSize, int *elementsArr, int targetVal) {
    for (int idx = 0; idx < arrSize; idx++) {
        if (elementsArr[idx] == targetVal) return idx;
    }
    return -1;
}

int main() {
    int nums[] = {2, 3, 4, 5, 3};
    printf("%d\n", linearSearch(5, nums, 3));
    return 0;
}
