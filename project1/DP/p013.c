#include <stdio.h>
#include <stdbool.h>

bool subsetSum(int arrLen, int arr[], int targetSum) {
    bool dpSubset[targetSum + 1];
    memset(dpSubset, false, sizeof(dpSubset));
    dpSubset[0] = true;

    for (int idx = 0; idx < arrLen; idx++) {
        for (int sum = targetSum; sum >= arr[idx]; sum--) {
            dpSubset[sum] = dpSubset[sum] || dpSubset[sum - arr[idx]];
        }
    }

    return dpSubset[targetSum];
}

int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    int len = 6;
    int target = 9;
    printf("%s\n", subsetSum(len, arr, target) ? "true" : "false");
    return 0;
}
