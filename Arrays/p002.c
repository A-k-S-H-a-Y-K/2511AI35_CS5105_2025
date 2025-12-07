#include <stdio.h>

void findSecondElements(int arrSize, int *elementsArr) {
    if (arrSize < 2) {
        printf("-1 -1\n");
        return;
    }

    int minVal = INT_MAX, secondMinVal = INT_MAX;
    int maxVal = INT_MIN, secondMaxVal = INT_MIN;

    for (int idx = 0; idx < arrSize; idx++) {
        if (elementsArr[idx] < minVal) {
            secondMinVal = minVal;
            minVal = elementsArr[idx];
        } else if (elementsArr[idx] < secondMinVal && elementsArr[idx] != minVal) {
            secondMinVal = elementsArr[idx];
        }

        if (elementsArr[idx] > maxVal) {
            secondMaxVal = maxVal;
            maxVal = elementsArr[idx];
        } else if (elementsArr[idx] > secondMaxVal && elementsArr[idx] != maxVal) {
            secondMaxVal = elementsArr[idx];
        }
    }

    printf("%d %d\n", secondMinVal == INT_MAX ? -1 : secondMinVal, 
                       secondMaxVal == INT_MIN ? -1 : secondMaxVal);
}

int main() {
    int nums[] = {1, 2, 4, 7, 7, 5};
    findSecondElements(6, nums);
    return 0;
}
