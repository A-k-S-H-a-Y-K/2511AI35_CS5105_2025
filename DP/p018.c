#include <stdio.h>
#include <string.h>

int targetSumWays(int arrLen, int arr[], int targetVal) {
    int totalSum = 0;
    for (int i = 0; i < arrLen; i++) totalSum += arr[i];

    if ((totalSum + targetVal) % 2 != 0) return 0;

    int subset1Sum = (totalSum + targetVal) / 2;
    int dpTarget[subset1Sum + 1];
    memset(dpTarget, 0, sizeof(dpTarget));
    dpTarget[0] = 1;

    for (int idx = 0; idx < arrLen; idx++) {
        for (int sum = subset1Sum; sum >= arr[idx]; sum--) {
            dpTarget[sum] += dpTarget[sum - arr[idx]];
        }
    }

    return dpTarget[subset1Sum];
}

int main() {
    int arr[] = {1, 1, 1, 1, 1};
    int len = 5;
    int target = 3;
    printf("%d\n", targetSumWays(len, arr, target));
    return 0;
}
