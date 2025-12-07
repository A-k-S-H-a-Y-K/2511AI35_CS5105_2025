#include <stdio.h>

long long ninjaTraining(int dayCount, int points[][3]) {
    long long dpScore[dayCount][3];

    dpScore[0][0] = points[0][0];
    dpScore[0][1] = points[0][1];
    dpScore[0][2] = points[0][2];

    for (int currDay = 1; currDay < dayCount; currDay++) {
        for (int currAct = 0; currAct < 3; currAct++) {
            long long maxPrev = 0;
            for (int prevAct = 0; prevAct < 3; prevAct++) {
                if (prevAct != currAct) {
                    maxPrev = (dpScore[currDay - 1][prevAct] > maxPrev) ? dpScore[currDay - 1][prevAct] : maxPrev;
                }
            }
            dpScore[currDay][currAct] = points[currDay][currAct] + maxPrev;
        }
    }

    long long finalResult = (dpScore[dayCount - 1][0] > dpScore[dayCount - 1][1]) ? dpScore[dayCount - 1][0] : dpScore[dayCount - 1][1];
    finalResult = (finalResult > dpScore[dayCount - 1][2]) ? finalResult : dpScore[dayCount - 1][2];

    return finalResult;
}

int main() {
    int points[][3] = {{10, 50, 1}, {5, 100, 11}};
    int days = 2;
    printf("%lld\n", ninjaTraining(days, points));
    return 0;
}
