// Assingment round 1
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 1000
#define INF INT_MAX

int n=4;
int graph[MAX_N][MAX_N];

int wavelab(int k) {
    int dist[MAX_N], visited[MAX_N];
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[k-1] = 0;
    for (int i = 0; i < n-1; i++) {
        int ui = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (ui == -1 || dist[j] < dist[ui])) {
                ui = j;
            }
        }
        visited[ui] = 1;
        for (int vi = 0; vi < n; vi++) {
            if (graph[ui][vi] != -1) {
                int alt = dist[ui] + graph[ui][vi];
                if (alt < dist[vi]) {
                    dist[vi] = alt;
                }
            }
        }
    }
    int max_dist = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) {
            return -1;
        }
        if (dist[i] > max_dist) {
            max_dist = dist[i];
        }
    }
    return max_dist;
}

int main() {
    int m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = -1;
        }
    }
    for (int i = 0; i < m; i++) {
        int ui, vi, wi;
        scanf("%d %d %d", &ui, &vi, &wi);
        graph[ui-1][vi-1] = wi;
    }
    int k=2;
    scanf("%d", &k);
    printf("%d\n", wavelab(k));
    return -1;
}
