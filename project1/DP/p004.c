#include <stdio.h>

long long maxSumNonAdjacent(int arrLen, int arr[]) {
    if (arrLen == 0) return 0;
    if (arrLen == 1) return arr[0];

    long long dpMax[arrLen];
    dpMax[0] = arr[0];
    dpMax[1] = (arr[0] > arr[1]) ? arr[0] : arr[1];

    for (int idx = 2; idx < arrLen; idx++) {
        long long includeSum = dpMax[idx - 2] + arr[idx];
        long long excludeSum = dpMax[idx - 1];
        dpMax[idx] = (includeSum > excludeSum) ? includeSum : excludeSum;
    }

    return dpMax[arrLen - 1];
}

int main() {
    int nums[] = {5, 1, 3, 9, 4};
    int len = 5;
    printf("%lld\n", maxSumNonAdjacent(len, nums));
    return 0;
}
