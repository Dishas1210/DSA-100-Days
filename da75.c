#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefix = 0;
    int maxLen = 0;

    /* Hash map simulation */
    int hash[2001];  // range for prefix sum
    for (int i = 0; i < 2001; i++)
        hash[i] = -2;   // -2 means not visited

    /* Important: prefix sum = 0 at index -1 */
    hash[1000] = -1;   // shift by +1000

    for (int i = 0; i < n; i++) {
        prefix += arr[i];

        int idx = prefix + 1000;

        if (hash[idx] != -2) {
            int len = i - hash[idx];
            if (len > maxLen)
                maxLen = len;
        } else {
            hash[idx] = i;
        }
    }

    printf("%d", maxLen);

    return 0;
}