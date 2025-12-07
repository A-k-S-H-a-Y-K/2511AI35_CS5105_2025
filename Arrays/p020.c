#include <stdio.h>

int longestSubarrayMixedSum(int arrSize, int *elementsArr, int targetSum) {
    int maxLen = 0;

    for (int start = 0; start < arrSize; start++) {
        int currSum = 0;
        for (int end = start; end < arrSize; end++) {
            currSum += elementsArr[end];
            if (currSum == targetSum) {
                maxLen = ((end - start + 1) > maxLen) ? (end - start + 1) : maxLen;
            }
        }
    }

    return maxLen;
}

int main() {
    int nums[] = {10, 5, 2, 7, 1, 9};
    printf("%d\n", longestSubarrayMixedSum(6, nums, 15));
    return 0;
}
