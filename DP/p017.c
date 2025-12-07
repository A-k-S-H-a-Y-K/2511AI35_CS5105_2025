#include <stdio.h>
#include <string.h>

int countPartitionDifference(int arrLen, int arr[], int diffTarget) {
    int totalSum = 0;
    for (int i = 0; i < arrLen; i++) totalSum += arr[i];

    if ((totalSum + diffTarget) % 2 != 0) return 0;

    int subset1Sum = (totalSum + diffTarget) / 2;
    int dpPartDiff[subset1Sum + 1];
    memset(dpPartDiff, 0, sizeof(dpPartDiff));
    dpPartDiff[0] = 1;

    for (int idx = 0; idx < arrLen; idx++) {
        for (int sum = subset1Sum; sum >= arr[idx]; sum--) {
            dpPartDiff[sum] += dpPartDiff[sum - arr[idx]];
        }
    }

    return dpPartDiff[subset1Sum];
}

int main() {
    int arr[] = {5, 2, 6, 4};
    int len = 4;
    int diff = 3;
    printf("%d\n", countPartitionDifference(len, arr, diff));
    return 0;
}
