#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALPHABET 26

typedef struct {
    int inDegreeVal;
    int neighborList[MAX_ALPHABET];
    int neighborCnt;
} GraphNode;

int findFirstDiff(char *wrdX, char *wrdY) {
    int minLenVal = strlen(wrdX) < strlen(wrdY) ? strlen(wrdX) : strlen(wrdY);
    for (int charPos = 0; charPos < minLenVal; charPos++) {
        if (wrdX[charPos] != wrdY[charPos]) {
            return charPos;
        }
    }
    return -1;
}

void kahnTopologicalSort(GraphNode *graphNodes, char *resultSequence) {
    int queue[MAX_ALPHABET];
    int qHead = 0, qTail = 0;

    for (int nodeIdx = 0; nodeIdx < MAX_ALPHABET; nodeIdx++) {
        if (graphNodes[nodeIdx].inDegreeVal == 0) {
            queue[qTail++] = nodeIdx;
        }
    }

    int resultLen = 0;

    while (qHead < qTail) {
        int currNodeIdx = queue[qHead++];
        resultSequence[resultLen++] = 'a' + currNodeIdx;

        for (int neighborPos = 0; neighborPos < graphNodes[currNodeIdx].neighborCnt; neighborPos++) {
            int neighborIdx = graphNodes[currNodeIdx].neighborList[neighborPos];
            graphNodes[neighborIdx].inDegreeVal--;

            if (graphNodes[neighborIdx].inDegreeVal == 0) {
                queue[qTail++] = neighborIdx;
            }
        }
    }

    resultSequence[resultLen] = '\0';
}

void buildAlienLanguageGraph(char **wordArray, int wordCount, GraphNode *graphNodes) {
    for (int i = 0; i < MAX_ALPHABET; i++) {
        graphNodes[i].inDegreeVal = 0;
        graphNodes[i].neighborCnt = 0;
    }

    for (int wIdx = 0; wIdx < wordCount - 1; wIdx++) {
        int diffPosition = findFirstDiff(wordArray[wIdx], wordArray[wIdx + 1]);

        if (diffPosition != -1) {
            int sourceCharIdx = wordArray[wIdx][diffPosition] - 'a';
            int destCharIdx = wordArray[wIdx + 1][diffPosition] - 'a';

            int edgeAlreadyExists = 0;
            for (int edgeIdx = 0; edgeIdx < graphNodes[sourceCharIdx].neighborCnt; edgeIdx++) {
                if (graphNodes[sourceCharIdx].neighborList[edgeIdx] == destCharIdx) {
                    edgeAlreadyExists = 1;
                    break;
                }
            }

            if (!edgeAlreadyExists) {
                graphNodes[sourceCharIdx].neighborList[graphNodes[sourceCharIdx].neighborCnt] = destCharIdx;
                graphNodes[sourceCharIdx].neighborCnt++;
                graphNodes[destCharIdx].inDegreeVal++;
            }
        }
    }
}

int main() {
    char *wordList1[] = {"baa", "abcd", "abca", "cab", "cad"};
    int wordCnt1 = 5;
    char resultOrder1[MAX_ALPHABET + 1];

    GraphNode graphNodes1[MAX_ALPHABET];
    buildAlienLanguageGraph(wordList1, wordCnt1, graphNodes1);
    kahnTopologicalSort(graphNodes1, resultOrder1);

    printf("Test Case 1:\n");
    printf("Input words: ");
    for (int i = 0; i < wordCnt1; i++) {
        printf("%s ", wordList1[i]);
    }
    printf("\nAlien Dictionary Order: %s\n\n", resultOrder1);

    char *wordList2[] = {"caa", "aaa", "aab"};
    int wordCnt2 = 3;
    char resultOrder2[MAX_ALPHABET + 1];

    GraphNode graphNodes2[MAX_ALPHABET];
    buildAlienLanguageGraph(wordList2, wordCnt2, graphNodes2);
    kahnTopologicalSort(graphNodes2, resultOrder2);

    printf("Test Case 2:\n");
    printf("Input words: ");
    for (int i = 0; i < wordCnt2; i++) {
        printf("%s ", wordList2[i]);
    }
    printf("\nAlien Dictionary Order: %s\n", resultOrder2);

    return 0;
}
