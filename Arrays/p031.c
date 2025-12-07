#include <stdio.h>

int largestSubarrayZeroSum(int arrSize, int *elementsArr) {
    int maxLen = 0;

    for (int start = 0; start < arrSize; start++) {
        int currSum = 0;
        for (int end = start; end < arrSize; end++) {
            currSum += elementsArr[end];
            if (currSum == 0) {
                maxLen = ((end - start + 1) > maxLen) ? (end - start + 1) : maxLen;
            }
        }
    }

    return maxLen;
}

int main() {
    int nums[] = {15, -2, 2, -8, 1, 7, 10, 23};
    printf("%d\n", largestSubarrayZeroSum(8, nums));
    return 0;
}
