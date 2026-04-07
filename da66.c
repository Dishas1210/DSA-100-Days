#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];
int V; // number of vertices

// DFS function to detect cycle
bool dfs(int node, bool visited[], bool recStack[]) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < V; i++) {
        if (graph[node][i]) {
            // If not visited, recurse
            if (!visited[i] && dfs(i, visited, recStack))
                return true;

            // If already in recursion stack → cycle
            else if (recStack[i])
                return true;
        }
    }

    recStack[node] = false; // remove from recursion stack
    return false;
}

// Function to check cycle
bool hasCycle() {
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, recStack))
                return true;
        }
    }
    return false;
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    if (hasCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}