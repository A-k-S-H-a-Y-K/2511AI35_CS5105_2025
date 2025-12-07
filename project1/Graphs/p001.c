#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *queue;
    int front, rear, capacity;
} BFSQueue;

void initQueue(BFSQueue *q, int capacity) {
    q->queue = (int *)malloc(capacity * sizeof(int));
    q->front = q->rear = 0;
    q->capacity = capacity;
}

void enqueue(BFSQueue *q, int val) {
    q->queue[q->rear++] = val;
}

int dequeue(BFSQueue *q) {
    return q->queue[q->front++];
}

int isEmpty(BFSQueue *q) {
    return q->front == q->rear;
}

void bfsTraversal(int vertexCount, int **adjMatrix, int *resultArr) {
    BFSQueue bfsQ;
    initQueue(&bfsQ, vertexCount);
    int visited[vertexCount];
    memset(visited, 0, sizeof(visited));

    enqueue(&bfsQ, 0);
    visited[0] = 1;
    int resultIdx = 0;

    while (!isEmpty(&bfsQ)) {
        int currNode = dequeue(&bfsQ);
        resultArr[resultIdx++] = currNode;

        for (int neighborIdx = 0; neighborIdx < vertexCount; neighborIdx++) {
            if (adjMatrix[currNode][neighborIdx] && !visited[neighborIdx]) {
                enqueue(&bfsQ, neighborIdx);
                visited[neighborIdx] = 1;
            }
        }
    }
    free(bfsQ.queue);
}

int main() {
    int adjMatrix[5][5] = {{0,1,1,0,0}, {1,0,0,1,1}, {1,0,0,1,0}, {0,1,1,0,0}, {0,1,0,0,0}};
    int *adj[5];
    for (int i = 0; i < 5; i++) adj[i] = (int *)adjMatrix[i];

    int result[5];
    bfsTraversal(5, adj, result);
    for (int i = 0; i < 5; i++) printf("%d ", result[i]);
    printf("\n");
    return 0;
}
