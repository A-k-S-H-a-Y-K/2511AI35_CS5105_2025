#include <stdio.h>
#include <string.h>

int cherryPickup(int rowCount, int colCount, int matrix[][colCount]) {
    int dp[rowCount][colCount][colCount];
    memset(dp, 0, sizeof(dp));

    dp[0][0][colCount - 1] = matrix[0][0] + ((colCount > 1) ? matrix[0][colCount - 1] : 0);

    for (int r = 1; r < rowCount; r++) {
        for (int c1 = 0; c1 < colCount; c1++) {
            for (int c2 = 0; c2 < colCount; c2++) {
                dp[r][c1][c2] = 0;

                for (int pc1 = c1 - 1; pc1 <= c1 + 1; pc1++) {
                    for (int pc2 = c2 - 1; pc2 <= c2 + 1; pc2++) {
                        if (pc1 >= 0 && pc1 < colCount && pc2 >= 0 && pc2 < colCount) {
                            int cherries = matrix[r][c1];
                            if (c1 != c2) cherries += matrix[r][c2];

                            int val = dp[r - 1][pc1][pc2] + cherries;
                            dp[r][c1][c2] = (val > dp[r][c1][c2]) ? val : dp[r][c1][c2];
                        }
                    }
                }
            }
        }
    }

    return dp[rowCount - 1][0][colCount - 1];
}

int main() {
    int matrix[][3] = {{3, 1, 1}, {2, 5, 1}, {1, 5, 5}};
    int rows = 3;
    int cols = 3;
    printf("%d\n", cherryPickup(rows, cols, matrix));
    return 0;
}
