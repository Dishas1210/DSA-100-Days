#include <stdio.h>

int main() {
    int m, n;

    // Read matrix size
    scanf("%d %d", &m, &n);

    int a[100][100];

    // Input matrix elements
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Condition 1: Matrix must be square
    if(m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    // Check symmetry
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {

            // Compare element with its transpose position
            if(a[i][j] != a[j][i]) {
                printf("Not a Symmetric Matrix");
                return 0;
            }
        }
    }

    // If all elements matched
    printf("Symmetric Matrix");

    return 0;
}