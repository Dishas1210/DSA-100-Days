#include <stdio.h>   // Needed for printf and scanf

// Recursive function to compute nth Fibonacci number
int fib(int n)
{
    // -------- Base cases (Stopping condition) --------
    // If n = 0 → Fibonacci number is 0
    if (n == 0)
        return 0;

    // If n = 1 → Fibonacci number is 1
    if (n == 1)
        return 1;

    // -------- Recursive case --------
    // fib(n) = fib(n-1) + fib(n-2)
    // Function calls itself for previous two values
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;

    // Read input value of n
    scanf("%d", &n);

    // Call fib function and print result
    printf("%d", fib(n));

    return 0;   // End of program
}
