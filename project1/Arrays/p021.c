#include <stdio.h>

int findTwoSum(int arrSize, int *elementsArr, int targetSum, int *resultArr) {
    for (int i = 0; i < arrSize; i++) {
        for (int j = i + 1; j < arrSize; j++) {
            if (elementsArr[i] + elementsArr[j] == targetSum) {
                resultArr[0] = i;
                resultArr[1] = j;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int nums[] = {1, 6, 2, 10, 3};
    int result[2];
    findTwoSum(5, nums, 7, result);
    printf("%d %d\n", result[0], result[1]);
    return 0;
}
