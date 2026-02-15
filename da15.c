#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    // Input matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int sum = 0;
    int limit = (m < n) ? m : n;   // minimum of rows and columns

    // Calculate primary diagonal sum
    for(int i = 0; i < limit; i++) {
        sum += matrix[i][i];
    }

    printf("%d", sum);

    return 0;
}