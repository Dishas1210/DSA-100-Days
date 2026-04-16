#include <stdio.h>
#include <string.h>

char findFirstNonRepeating(char *s) {
    int freq[26] = {0}; // Initialize frequency array for a-z
    int n = strlen(s);

    // First pass: Count frequency of each character
    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
    }

    // Second pass: Find the first character with a frequency of 1
    for (int i = 0; i < n; i++) {
        if (freq[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    return '$'; // Return '$' if no non-repeating character exists
}

int main() {
    char s[100000]; // Buffer for input string
    if (scanf("%s", s) == 1) {
        printf("%c\n", findFirstNonRepeating(s));
    }
    return 0;
}
