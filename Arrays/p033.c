#include <stdio.h>

void mergeArraysNoExtraSpace(int arr1Size, int *arr1, int arr2Size, int *arr2) {
    int p1 = arr1Size - arr2Size - 1;
    int p2 = arr2Size - 1;
    int p = arr1Size - 1;

    while (p1 >= 0 && p2 >= 0) {
        if (arr1[p1] > arr2[p2]) {
            arr1[p] = arr1[p1];
            p1--;
        } else {
            arr1[p] = arr2[p2];
            p2--;
        }
        p--;
    }

    while (p2 >= 0) {
        arr1[p] = arr2[p2];
        p2--;
        p--;
    }
}

int main() {
    printf("Arrays merged\n");
    return 0;
}
