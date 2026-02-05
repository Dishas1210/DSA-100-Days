#include <stdio.h>

int main() {
    int p, q;
    int a[100], b[100], c[200];
    int i = 0, j = 0, k = 0;

    // input size of first log
    scanf("%d", &p);

    // input first sorted array
    for (i = 0; i < p; i++)
        scanf("%d", &a[i]);

    // input size of second log
    scanf("%d", &q);

    // input second sorted array
    for (j = 0; j < q; j++)
        scanf("%d", &b[j]);

    i = 0;
    j = 0;

    // merge process
    while (i < p && j < q) {
        if (a[i] <= b[j]) {
            c[k] = a[i];
            i++;
        } else {
            c[k] = b[j];
            j++;
        }
        k++;
    }

    // remaining elements of a
    while (i < p) {
        c[k] = a[i];
        i++;
        k++;
    }

    // remaining elements of b
    while (j < q) {
        c[k] = b[j];
        j++;
        k++;
    }

    // print merged array
    for (int t = 0; t < k; t++)
        printf("%d ", c[t]);

    return 0;
}