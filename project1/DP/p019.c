#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool wildcardMatch(char s1[], char s2[]) {
    int s1Len = strlen(s1);
    int s2Len = strlen(s2);
    bool dpMatch[s1Len + 1][s2Len + 1];

    memset(dpMatch, false, sizeof(dpMatch));
    dpMatch[0][0] = true;

    for (int j = 1; j <= s2Len; j++) {
        if (s1[j - 1] == '*') {
            dpMatch[j][0] = dpMatch[j - 1][0];
        }
    }

    for (int i = 1; i <= s1Len; i++) {
        for (int j = 1; j <= s2Len; j++) {
            if (s1[i - 1] == '*') {
                dpMatch[i][j] = dpMatch[i - 1][j] || dpMatch[i][j - 1];
            } else if (s1[i - 1] == '?' || s1[i - 1] == s2[j - 1]) {
                dpMatch[i][j] = dpMatch[i - 1][j - 1];
            } else {
                dpMatch[i][j] = false;
            }
        }
    }

    return dpMatch[s1Len][s2Len];
}

int main() {
    char s1[] = "ab*cd";
    char s2[] = "abefcd";
    printf("%s\n", wildcardMatch(s1, s2) ? "true" : "false");
    return 0;
}
