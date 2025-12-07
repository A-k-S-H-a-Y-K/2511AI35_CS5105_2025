#include <stdio.h>

int countXorSubarrays(int arrSize, int *elementsArr, int targetXor) {
    int xorCount = 0;

    for (int start = 0; start < arrSize; start++) {
        int currXor = 0;
        for (int end = start; end < arrSize; end++) {
            currXor ^= elementsArr[end];
            if (currXor == targetXor) xorCount++;
        }
    }

    return xorCount;
}

int main() {
    int nums[] = {4, 2, 2, 6, 4};
    printf("%d\n", countXorSubarrays(5, nums, 6));
    return 0;
}
