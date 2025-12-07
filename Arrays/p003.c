#include <stdio.h>
#include <stdbool.h>

bool isArraySorted(int arrSize, int *elementsArr) {
    for (int idx = 1; idx < arrSize; idx++) {
        if (elementsArr[idx] < elementsArr[idx - 1]) return false;
    }
    return true;
}

int main() {
    int nums[] = {1, 2, 3, 4, 5};
    printf("%s\n", isArraySorted(5, nums) ? "true" : "false");
    return 0;
}
