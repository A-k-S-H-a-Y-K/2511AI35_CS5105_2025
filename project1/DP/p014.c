#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool partitionEqualSubset(int arrLen, int arr[]) {
    int totalSum = 0;
    for (int i = 0; i < arrLen; i++) totalSum += arr[i];

    if (totalSum % 2 != 0) return false;

    int targetSum = totalSum / 2;
    bool dpPartition[targetSum + 1];
    memset(dpPartition, false, sizeof(dpPartition));
    dpPartition[0] = true;

    for (int idx = 0; idx < arrLen; idx++) {
        for (int sum = targetSum; sum >= arr[idx]; sum--) {
            dpPartition[sum] = dpPartition[sum] || dpPartition[sum - arr[idx]];
        }
    }

    return dpPartition[targetSum];
}

int main() {
    int arr[] = {1, 5, 11, 5};
    int len = 4;
    printf("%s\n", partitionEqualSubset(len, arr) ? "true" : "false");
    return 0;
}
