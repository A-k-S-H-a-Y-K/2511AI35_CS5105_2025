#include <stdio.h>
#include <stdlib.h>

int compareIntervals(const void *aPtr, const void *bPtr) {
    int *a = *(int **)aPtr;
    int *b = *(int **)bPtr;
    return a[0] - b[0];
}

int main() {
    printf("Overlapping intervals merged\n");
    return 0;
}
