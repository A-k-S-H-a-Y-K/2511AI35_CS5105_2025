#include <stdio.h>
#include <limits.h>

long long kadaneMaxSubarrayV2(int arrSize, int *elementsArr) {
    long long maxSum = LLONG_MIN;
    long long currSum = 0;

    for (int idx = 0; idx < arrSize; idx++) {
        currSum += elementsArr[idx];
        maxSum = (currSum > maxSum) ? currSum : maxSum;
        if (currSum < 0) currSum = 0;
    }

    return maxSum;
}

int main() {
    int nums[] = {2, 3, 5, -2, 7, -4};
    printf("%lld\n", kadaneMaxSubarrayV2(6, nums));
    return 0;
}
