#include <stdio.h>

void sortColors(int arrSize, int *elementsArr) {
    int lowPtr = 0, midPtr = 0, highPtr = arrSize - 1;

    while (midPtr <= highPtr) {
        if (elementsArr[midPtr] == 0) {
            int temp = elementsArr[lowPtr];
            elementsArr[lowPtr] = elementsArr[midPtr];
            elementsArr[midPtr] = temp;
            lowPtr++;
            midPtr++;
        } else if (elementsArr[midPtr] == 1) {
            midPtr++;
        } else {
            int temp = elementsArr[midPtr];
            elementsArr[midPtr] = elementsArr[highPtr];
            elementsArr[highPtr] = temp;
            highPtr--;
        }
    }
}

int main() {
    int nums[] = {1, 0, 2, 1, 0};
    sortColors(5, nums);
    for (int i = 0; i < 5; i++) printf("%d ", nums[i]);
    printf("\n");
    return 0;
}
