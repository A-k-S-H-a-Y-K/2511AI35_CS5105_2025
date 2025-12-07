#include <stdio.h>
#include <stdlib.h>

int frogJumpEnergy(int numStairs, int heights[]) {
    if (numStairs == 0) return 0;
    if (numStairs == 1) return 0;

    int dpEnergy[numStairs];
    dpEnergy[0] = 0;
    dpEnergy[1] = abs(heights[1] - heights[0]);

    for (int pos = 2; pos < numStairs; pos++) {
        int oneStep = dpEnergy[pos - 1] + abs(heights[pos] - heights[pos - 1]);
        int twoSteps = dpEnergy[pos - 2] + abs(heights[pos] - heights[pos - 2]);
        dpEnergy[pos] = (oneStep < twoSteps) ? oneStep : twoSteps;
    }

    return dpEnergy[numStairs - 1];
}

int main() {
    int stairHeights[] = {10, 20, 30, 10};
    int numStairs = 4;
    printf("%d\n", frogJumpEnergy(numStairs, stairHeights));
    return 0;
}
