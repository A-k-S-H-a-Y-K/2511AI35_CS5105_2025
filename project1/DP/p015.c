#include <stdio.h>
#include <string.h>

int minimumSubsetDifference(int arrLen, int arr[]) {
    int totalSum = 0;
    for (int i = 0; i < arrLen; i++) totalSum += arr[i];

    bool dpDiff[totalSum + 1];
    memset(dpDiff, false, sizeof(dpDiff));
    dpDiff[0] = true;

    for (int idx = 0; idx < arrLen; idx++) {
        for (int sum = totalSum; sum >= arr[idx]; sum--) {
            dpDiff[sum] = dpDiff[sum] || dpDiff[sum - arr[idx]];
        }
    }

    int minDiff = totalSum;
    for (int sum = 0; sum <= totalSum / 2; sum++) {
        if (dpDiff[sum]) {
            int diff = (totalSum - 2 * sum);
            minDiff = (diff < minDiff) ? diff : minDiff;
        }
    }

    return minDiff;
}

int main() {
    int arr[] = {1, 5, 11, 5};
    int len = 4;
    printf("%d\n", minimumSubsetDifference(len, arr));
    return 0;
}
