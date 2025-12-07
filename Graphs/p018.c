#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { char *word; int level; } WordNode;

int wordLadderLength(char **wordList, int wordCount, char *startWord, char *targetWord) {
    for (int i = 0; i < wordCount; i++) {
        if (strcmp(wordList[i], targetWord) == 0) break;
        if (i == wordCount - 1) return 0;
    }

    WordNode queue[wordCount + 1];
    int qIdx = 0, fIdx = 0;

    queue[qIdx].word = startWord;
    queue[qIdx].level = 1;
    qIdx++;

    int visited[wordCount];
    memset(visited, 0, sizeof(visited));

    int wordLen = strlen(startWord);

    while (fIdx < qIdx) {
        char *currWord = queue[fIdx].word;
        int currLevel = queue[fIdx].level;
        fIdx++;

        if (strcmp(currWord, targetWord) == 0) return currLevel;

        for (int listIdx = 0; listIdx < wordCount; listIdx++) {
            if (!visited[listIdx]) {
                int diffCount = 0;
                for (int charIdx = 0; charIdx < wordLen; charIdx++) {
                    if (currWord[charIdx] != wordList[listIdx][charIdx]) diffCount++;
                }

                if (diffCount == 1) {
                    visited[listIdx] = 1;
                    queue[qIdx].word = wordList[listIdx];
                    queue[qIdx].level = currLevel + 1;
                    qIdx++;
                }
            }
        }
    }
    return 0;
}

int main() {
    char *words[] = {"des", "der", "dfr", "dgt", "dfs"};
    printf("%d\n", wordLadderLength(words, 5, "der", "dfs"));
    return 0;
}
