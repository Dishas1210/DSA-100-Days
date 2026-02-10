#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int left, right;

    // read string
    scanf("%s", s);

    // find last index
    right = strlen(s) - 1;
    left = 0;

    // two pointer comparison
    while (left < right)
    {
        if (s[left] != s[right])
        {
            printf("NO");
            return 0;
        }

        left++;
        right--;
    }

    printf("YES");
    return 0;
}