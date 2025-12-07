#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int remainder, steps;
} MultiplicationNode;

int minimumMultiplications(int *arrData, int arrSize, int startVal, int endVal) {
    int distance[100000];
    memset(distance, -1, sizeof(distance));
    distance[startVal] = 0;

    MultiplicationNode queue[100000];
    int qIdx = 0, fIdx = 0;

    queue[qIdx].remainder = startVal;
    queue[qIdx].steps = 0;
    qIdx++;

    while (fIdx < qIdx) {
        MultiplicationNode curr = queue[fIdx++];

        if (curr.remainder == endVal) return curr.steps;

        for (int i = 0; i < arrSize; i++) {
            int nextRem = (curr.remainder * arrData[i]) % 100000;

            if (distance[nextRem] == -1) {
                distance[nextRem] = curr.steps + 1;
                queue[qIdx].remainder = nextRem;
                queue[qIdx].steps = curr.steps + 1;
                qIdx++;
            }
        }
    }

    return distance[endVal];
}

int main() {
    int arr[] = {2, 5, 7};
    printf("%d\n", minimumMultiplications(arr, 3, 3, 30));
    return 0;
}
