#include <stdio.h>

void rotateArrayLeft(int arrSize, int *elementsArr) {
    int firstElem = elementsArr[0];
    for (int idx = 0; idx < arrSize - 1; idx++) {
        elementsArr[idx] = elementsArr[idx + 1];
    }
    elementsArr[arrSize - 1] = firstElem;
}

int main() {
    int nums[] = {1, 2, 3, 4, 5};
    rotateArrayLeft(5, nums);
    for (int i = 0; i < 5; i++) printf("%d ", nums[i]);
    printf("\n");
    return 0;
}
