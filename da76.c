#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];

void dfs(int node, int n) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    // input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;  // convert to 0-based
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // DFS from node 0
    dfs(0, n);

    // check if all nodes visited
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");
    return 0;
}