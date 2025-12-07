#include <stdio.h>

int countSubarraysWithSum(int arrSize, int *elementsArr, int targetSum) {
    int countVal = 0;

    for (int start = 0; start < arrSize; start++) {
        int currSum = 0;
        for (int end = start; end < arrSize; end++) {
            currSum += elementsArr[end];
            if (currSum == targetSum) countVal++;
        }
    }

    return countVal;
}

int main() {
    int nums[] = {1, 1, 1};
    printf("%d\n", countSubarraysWithSum(3, nums, 2));
    return 0;
}
