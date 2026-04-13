#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    scanf("%s", str);

    int seen[26] = {0}; // for lowercase letters

    for(int i = 0; str[i] != '\0'; i++) {
        int index = str[i] - 'a';

        if(seen[index] == 1) {
            printf("%c", str[i]);
            return 0;
        }

        seen[index] = 1;
    }

    printf("-1");
    return 0;
}