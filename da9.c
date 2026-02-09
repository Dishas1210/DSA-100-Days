#include <stdio.h>

// recursive function to print string in reverse
void mirror(char str[], int index)
{
    // base case: end of string reached
    if (str[index] == '\0')
        return;

    // go forward first
    mirror(str, index + 1);

    // print while coming back (reverse order)
    printf("%c", str[index]);
}

int main()
{
    char str[100];

    // read string
    scanf("%s", str);

    // call recursive function
    mirror(str, 0);

    return 0;
}