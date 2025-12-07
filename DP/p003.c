#include <stdio.h>
#include <stdlib.h>

int frogJumpKSteps(int numStairs, int heights[], int maxJump) {
    if (numStairs == 0) return 0;

    int dpMinEnergy[numStairs];
    dpMinEnergy[0] = 0;

    for (int currPos = 1; currPos < numStairs; currPos++) {
        dpMinEnergy[currPos] = INT_MAX;

        for (int jumpSize = 1; jumpSize <= maxJump && currPos - jumpSize >= 0; jumpSize++) {
            int prevPos = currPos - jumpSize;
            int jumpCost = dpMinEnergy[prevPos] + abs(heights[currPos] - heights[prevPos]);
            dpMinEnergy[currPos] = (jumpCost < dpMinEnergy[currPos]) ? jumpCost : dpMinEnergy[currPos];
        }
    }

    return dpMinEnergy[numStairs - 1];
}

int main() {
    int stairHeights[] = {10, 50, 10, 60, 30};
    int numStairs = 5;
    int maxJump = 3;
    printf("%d\n", frogJumpKSteps(numStairs, stairHeights, maxJump));
    return 0;
}
