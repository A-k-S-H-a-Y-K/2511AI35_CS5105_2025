#include <stdio.h>
#include <limits.h>

long long maxProductSubarray(int arrSize, int *elementsArr) {
    long long maxProd = elementsArr[0];
    long long minProd = elementsArr[0];
    long long resultProd = elementsArr[0];

    for (int idx = 1; idx < arrSize; idx++) {
        long long tempMax = maxProd;
        maxProd = (elementsArr[idx] * maxProd > elementsArr[idx] * minProd) ? 
                  elementsArr[idx] * maxProd : elementsArr[idx] * minProd;
        maxProd = (elementsArr[idx] > maxProd) ? elementsArr[idx] : maxProd;
        minProd = (elementsArr[idx] * tempMax < elementsArr[idx] * minProd) ? 
                  elementsArr[idx] * tempMax : elementsArr[idx] * minProd;
        minProd = (elementsArr[idx] < minProd) ? elementsArr[idx] : minProd;
        resultProd = (maxProd > resultProd) ? maxProd : resultProd;
    }

    return resultProd;
}

int main() {
    int nums[] = {4, 5, 3, 7, 1, 2};
    printf("%lld\n", maxProductSubarray(6, nums));
    return 0;
}
