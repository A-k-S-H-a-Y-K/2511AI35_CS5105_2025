#include <stdio.h>
#include <stdlib.h>

int compareSort(const void *aPtr, const void *bPtr) {
    return (*(int *)aPtr - *(int *)bPtr);
}

int findUnionSize(int arr1Size, int *arr1, int arr2Size, int *arr2) {
    int unionArr[arr1Size + arr2Size];
    int unionIdx = 0;

    for (int i = 0; i < arr1Size; i++) unionArr[unionIdx++] = arr1[i];
    for (int i = 0; i < arr2Size; i++) unionArr[unionIdx++] = arr2[i];

    qsort(unionArr, unionIdx, sizeof(int), compareSort);

    int uniqueCount = 1;
    for (int idx = 1; idx < unionIdx; idx++) {
        if (unionArr[idx] != unionArr[idx - 1]) uniqueCount++;
    }

    return uniqueCount;
}

int main() {
    int nums1[] = {1, 2, 3, 4, 5};
    int nums2[] = {1, 2, 7};
    printf("%d\n", findUnionSize(5, nums1, 3, nums2));
    return 0;
}
