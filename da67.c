#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX], top = -1;
int visited[MAX];
int adj[MAX][MAX];
int n;

// Push to stack
void push(int v) {
    stack[++top] = v;
}

// DFS function
void dfs(int v) {
    visited[v] = 1;

    for(int i = 0; i < n; i++) {
        if(adj[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }

    push(v);  // push after visiting all neighbors
}

// Topological Sort
void topologicalSort() {
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }

    printf("Topological Order: ");
    while(top != -1) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Initialize visited
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    topologicalSort();

    return 0;
}