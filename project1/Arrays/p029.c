#include <stdio.h>

int findMajorityN3(int arrSize, int *elementsArr, int *resultArr) {
    int elem1 = -1, elem2 = -1, count1 = 0, count2 = 0;

    for (int idx = 0; idx < arrSize; idx++) {
        if (elementsArr[idx] == elem1) count1++;
        else if (elementsArr[idx] == elem2) count2++;
        else if (count1 == 0) {
            elem1 = elementsArr[idx];
            count1 = 1;
        } else if (count2 == 0) {
            elem2 = elementsArr[idx];
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;
    for (int idx = 0; idx < arrSize; idx++) {
        if (elementsArr[idx] == elem1) count1++;
        else if (elementsArr[idx] == elem2) count2++;
    }

    int resultIdx = 0;
    int threshold = arrSize / 3;
    if (count1 > threshold) resultArr[resultIdx++] = elem1;
    if (count2 > threshold) resultArr[resultIdx++] = elem2;

    return resultIdx;
}

int main() {
    int nums[] = {1, 2, 1, 1, 3, 2};
    int result[2];
    findMajorityN3(6, nums, result);
    printf("Majority elements found\n");
    return 0;
}
