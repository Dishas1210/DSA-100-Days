#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Check if we can place k cows with at least 'dist' distance apart
int canPlaceCows(int arr[], int n, int k, int dist) {
    int count = 1; // Place first cow in the first stall
    int last_pos = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] - last_pos >= dist) {
            count++;
            last_pos = arr[i];
            if (count >= k) return 1;
        }
    }
    return 0;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int *stalls = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    qsort(stalls, n, sizeof(int), compare);

    int low = 1, high = stalls[n - 1] - stalls[0];
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlaceCows(stalls, n, k, mid)) {
            result = mid; // Update result and try for a larger distance
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%d\n", result);

    free(stalls);
    return 0;
}
