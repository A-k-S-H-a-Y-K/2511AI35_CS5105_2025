#include <stdio.h>
#include <string.h>

long long climbStairsTabulation(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;

    long long dpWays[n + 1];
    dpWays[0] = 1;
    dpWays[1] = 1;

    for (int idx = 2; idx <= n; idx++) {
        dpWays[idx] = dpWays[idx - 1] + dpWays[idx - 2];
    }

    return dpWays[n];
}

int main() {
    int numStairs = 4;
    printf("%lld\n", climbStairsTabulation(numStairs));
    return 0;
}
