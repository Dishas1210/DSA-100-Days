#include <stdio.h>
#include <limits.h>

#define MAX 100

int graph[MAX][MAX];

/* Function to find vertex with minimum distance */
int minDistance(int dist[], int visited[], int n) {
    int min = INT_MAX, min_index = -1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }

    return min_index;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    /* Initialize graph */
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    int u, v, w;

    /* Input edges (DIRECTED GRAPH) */
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;   // ✅ only one direction
    }

    int source;
    scanf("%d", &source);

    int dist[MAX];
    int visited[MAX];

    /* Initialize distances */
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[source] = 0;

    /* Dijkstra Algorithm */
    for (int count = 1; count <= n; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !visited[v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    /* Print result */
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}