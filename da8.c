#include <stdio.h>

// Recursive function to compute a^b
int power(int a, int b)
{
    // Base case: anything power 0 = 1
    if (b == 0)
        return 1;

    // Recursive case
    return a * power(a, b - 1);
}

int main()
{
    int a, b;

    // Input a and b
    scanf("%d %d", &a, &b);

    // Call function and print result
    printf("%d", power(a, b));

    return 0;
}