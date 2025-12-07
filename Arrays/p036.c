#include <stdio.h>

void findMissingRepeating(int arrSize, int *elementsArr, int *resultArr) {
    int elementsSet[arrSize + 1];
    for (int i = 0; i <= arrSize; i++) elementsSet[i] = 0;

    int repeating = -1;
    for (int idx = 0; idx < arrSize; idx++) {
        if (elementsSet[elementsArr[idx]] == 1) {
            repeating = elementsArr[idx];
        }
        elementsSet[elementsArr[idx]]++;
    }

    int missing = -1;
    for (int idx = 1; idx <= arrSize; idx++) {
        if (elementsSet[idx] == 0) {
            missing = idx;
            break;
        }
    }

    resultArr[0] = repeating;
    resultArr[1] = missing;
}

int main() {
    int nums[] = {3, 5, 4, 1, 1};
    int result[2];
    findMissingRepeating(5, nums, result);
    printf("%d %d\n", result[0], result[1]);
    return 0;
}
