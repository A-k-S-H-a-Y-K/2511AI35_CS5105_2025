#include <stdio.h>
#include <string.h>

#define INF 1e9

int findTheCity(int cityCount, int **edgesList, int edgeCount, int distanceThreshold) {
    int distance[cityCount][cityCount];

    for (int i = 0; i < cityCount; i++) {
        for (int j = 0; j < cityCount; j++) {
            distance[i][j] = (i == j) ? 0 : INF;
        }
    }

    for (int edgeIdx = 0; edgeIdx < edgeCount; edgeIdx++) {
        int u = edgesList[edgeIdx][0];
        int v = edgesList[edgeIdx][1];
        int w = edgesList[edgeIdx][2];
        distance[u][v] = distance[v][u] = w;
    }

    for (int k = 0; k < cityCount; k++) {
        for (int i = 0; i < cityCount; i++) {
            for (int j = 0; j < cityCount; j++) {
                distance[i][j] = (distance[i][k] + distance[k][j] < distance[i][j]) ?
                    distance[i][k] + distance[k][j] : distance[i][j];
            }
        }
    }

    int resultCity = -1, minNeighbors = cityCount;

    for (int cityIdx = 0; cityIdx < cityCount; cityIdx++) {
        int neighborCount = 0;
        for (int otherCity = 0; otherCity < cityCount; otherCity++) {
            if (distance[cityIdx][otherCity] <= distanceThreshold) {
                neighborCount++;
            }
        }

        if (neighborCount <= minNeighbors) {
            minNeighbors = neighborCount;
            resultCity = cityIdx;
        }
    }

    return resultCity;
}

int main() {
    printf("Find City With Smallest Neighbors\n");
    return 0;
}
