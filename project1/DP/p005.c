#include <stdio.h>

long long robberHelper(int houseCount, int moneyArr[], int startIdx, int endIdx) {
    if (startIdx > endIdx) return 0;
    if (startIdx == endIdx) return moneyArr[startIdx];

    long long dpRobbery[houseCount];
    dpRobbery[startIdx] = moneyArr[startIdx];
    dpRobbery[startIdx + 1] = (moneyArr[startIdx] > moneyArr[startIdx + 1]) ? moneyArr[startIdx] : moneyArr[startIdx + 1];

    for (int houseIdx = startIdx + 2; houseIdx <= endIdx; houseIdx++) {
        long long robCurr = dpRobbery[houseIdx - 2] + moneyArr[houseIdx];
        long long skipCurr = dpRobbery[houseIdx - 1];
        dpRobbery[houseIdx] = (robCurr > skipCurr) ? robCurr : skipCurr;
    }

    return dpRobbery[endIdx];
}

long long circularRobber(int houseCount, int moneyArr[]) {
    if (houseCount == 0) return 0;
    if (houseCount == 1) return moneyArr[0];

    long long opt1 = robberHelper(houseCount, moneyArr, 0, houseCount - 2);
    long long opt2 = robberHelper(houseCount, moneyArr, 1, houseCount - 1);

    return (opt1 > opt2) ? opt1 : opt2;
}

int main() {
    int money[] = {1, 3, 1, 3, 100};
    int houses = 5;
    printf("%lld\n", circularRobber(houses, money));
    return 0;
}
