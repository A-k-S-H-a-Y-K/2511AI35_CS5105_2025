#include <stdio.h>

int maxStockProfit(int arrSize, int *pricesArr) {
    int minPrice = pricesArr[0];
    int maxProfit = 0;

    for (int idx = 1; idx < arrSize; idx++) {
        int profitVal = pricesArr[idx] - minPrice;
        maxProfit = (profitVal > maxProfit) ? profitVal : maxProfit;
        minPrice = (pricesArr[idx] < minPrice) ? pricesArr[idx] : minPrice;
    }

    return maxProfit;
}

int main() {
    int prices[] = {10, 7, 5, 8, 11, 9};
    printf("%d\n", maxStockProfit(6, prices));
    return 0;
}
