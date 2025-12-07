#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int r, c, effort;
} EffortNode;

int compareEffort(const void *a, const void *b) {
    return ((EffortNode *)a)->effort - ((EffortNode *)b)->effort;
}

int minimumEffortPath(int rows, int cols, int **heightsData) {
    int effort[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            effort[i][j] = INT_MAX;
        }
    }
    effort[0][0] = 0;

    EffortNode pq[rows * cols * 10];
    int pqSize = 0;
    pq[pqSize].r = 0;
    pq[pqSize].c = 0;
    pq[pqSize].effort = 0;
    pqSize++;

    int visited[rows][cols];
    memset(visited, 0, sizeof(visited));
    int dirs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    while (pqSize > 0) {
        qsort(pq, pqSize, sizeof(EffortNode), compareEffort);
        EffortNode curr = pq[0];
        for (int i = 0; i < pqSize - 1; i++) pq[i] = pq[i + 1];
        pqSize--;

        if (visited[curr.r][curr.c]) continue;
        visited[curr.r][curr.c] = 1;

        if (curr.r == rows - 1 && curr.c == cols - 1) return curr.effort;

        for (int d = 0; d < 4; d++) {
            int nr = curr.r + dirs[d][0];
            int nc = curr.c + dirs[d][1];

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc]) {
                int maxEffort = (heightsData[curr.r][curr.c] > heightsData[nr][nc]) ?
                    heightsData[curr.r][curr.c] - heightsData[nr][nc] :
                    heightsData[nr][nc] - heightsData[curr.r][curr.c];
                maxEffort = (maxEffort > curr.effort) ? maxEffort : curr.effort;

                if (maxEffort < effort[nr][nc]) {
                    effort[nr][nc] = maxEffort;
                    pq[pqSize].r = nr;
                    pq[pqSize].c = nc;
                    pq[pqSize].effort = maxEffort;
                    pqSize++;
                }
            }
        }
    }
    return effort[rows-1][cols-1];
}

int main() {
    int heights[3][3] = {{1,2,2}, {3,8,2}, {5,3,5}};
    int *hPtr[3];
    for (int i = 0; i < 3; i++) hPtr[i] = (int *)heights[i];

    printf("%d\n", minimumEffortPath(3, 3, hPtr));
    return 0;
}
