#include <stdio.h>
#include <string.h>

int countSubsetsSum(int arrLen, int arr[], int targetSum) {
    int dpCount[targetSum + 1];
    memset(dpCount, 0, sizeof(dpCount));
    dpCount[0] = 1;

    for (int idx = 0; idx < arrLen; idx++) {
        for (int sum = targetSum; sum >= arr[idx]; sum--) {
            dpCount[sum] += dpCount[sum - arr[idx]];
        }
    }

    return dpCount[targetSum];
}

int main() {
    int arr[] = {1, 1, 1, 1};
    int len = 4;
    int target = 2;
    printf("%d\n", countSubsetsSum(len, arr, target));
    return 0;
}
