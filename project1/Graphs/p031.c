#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1e9

typedef struct {
    int node, cost, stops;
} FlightNode;

int compareFlights(const void *a, const void *b) {
    return ((FlightNode *)a)->cost - ((FlightNode *)b)->cost;
}

int findCheapestFlight(int cityCount, int **flightsList, int flightCount, int source, int destination, int maxStops) {
    int distance[cityCount];
    int stopCnt[cityCount];

    for (int i = 0; i < cityCount; i++) {
        distance[i] = INF;
        stopCnt[i] = maxStops + 1;
    }
    distance[source] = 0;
    stopCnt[source] = 0;

    FlightNode pq[flightCount * 10];
    int pqSize = 0;
    pq[pqSize].node = source;
    pq[pqSize].cost = 0;
    pq[pqSize].stops = 0;
    pqSize++;

    while (pqSize > 0) {
        qsort(pq, pqSize, sizeof(FlightNode), compareFlights);
        FlightNode curr = pq[0];
        for (int i = 0; i < pqSize - 1; i++) pq[i] = pq[i + 1];
        pqSize--;

        if (curr.stops > maxStops || curr.cost > distance[curr.node]) continue;

        for (int flightIdx = 0; flightIdx < flightCount; flightIdx++) {
            if (flightsList[flightIdx][0] == curr.node) {
                int nextNode = flightsList[flightIdx][1];
                int flightPrice = flightsList[flightIdx][2];

                if (curr.cost + flightPrice < distance[nextNode] && curr.stops + 1 <= maxStops) {
                    distance[nextNode] = curr.cost + flightPrice;
                    pq[pqSize].node = nextNode;
                    pq[pqSize].cost = distance[nextNode];
                    pq[pqSize].stops = curr.stops + 1;
                    pqSize++;
                }
            }
        }
    }

    return distance[destination] == INF ? -1 : distance[destination];
}

int main() {
    printf("Cheapest Flights Within K Stops\n");
    return 0;
}
