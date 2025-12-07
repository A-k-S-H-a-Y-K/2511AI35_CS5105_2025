#include <stdio.h>

int findMajority(int arrSize, int *elementsArr) {
    int majorityCandidate = elementsArr[0];
    int countVal = 1;

    for (int idx = 1; idx < arrSize; idx++) {
        if (elementsArr[idx] == majorityCandidate) {
            countVal++;
        } else {
            countVal--;
            if (countVal == 0) {
                majorityCandidate = elementsArr[idx];
                countVal = 1;
            }
        }
    }

    return majorityCandidate;
}

int main() {
    int nums[] = {7, 0, 0, 1, 7, 7, 2, 7, 7};
    printf("%d\n", findMajority(9, nums));
    return 0;
}
