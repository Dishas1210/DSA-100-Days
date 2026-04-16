#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    int n;
    scanf("%d", &n);

    char votes[MAX][50];
    int freq[MAX] = {0};
    int used[MAX] = {0};

    /* Input all votes */
    for (int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }

    /* Count frequency manually */
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;

        freq[i] = 1;
        used[i] = 1;

        for (int j = i + 1; j < n; j++) {
            if (strcmp(votes[i], votes[j]) == 0) {
                freq[i]++;
                used[j] = 1;
            }
        }
    }

    /* Find winner */
    char winner[50] = "";
    int maxVotes = 0;

    for (int i = 0; i < n; i++) {
        if (used[i]) {  // only unique names
            if (freq[i] > maxVotes) {
                maxVotes = freq[i];
                strcpy(winner, votes[i]);
            }
            else if (freq[i] == maxVotes) {
                if (strcmp(votes[i], winner) < 0) {
                    strcpy(winner, votes[i]);
                }
            }
        }
    }

    printf("%s %d", winner, maxVotes);

    return 0;
}