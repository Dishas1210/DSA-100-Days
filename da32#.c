#include <stdio.h>

#define MAX 100   // Maximum size of stack

int stack[MAX];   // Array to store stack elements
int top = -1;     // Top pointer (initially -1 means stack is empty)

/* Function to push an element into the stack */
void push(int value) {

    // Check for stack overflow
    if(top < MAX - 1) {
        top++;                 // Move top one position up
        stack[top] = value;    // Insert element at top
    }
}

/* Function to pop an element from the stack */
void pop() {

    // Check for stack underflow (empty stack)
    if(top == -1) {
        printf("Stack Underflow\n");
    } 
    else {
        printf("%d\n", stack[top]);  // Print top element
        top--;                      // Remove element by decreasing top
    }
}

/* Function to display stack elements from top to bottom */
void display() {

    // If stack is not empty
    if(top != -1) {

        // Print elements from top to bottom
        for(int i = top; i >= 0; i--) {
            printf("%d", stack[i]);

            // Avoid printing extra space after last element
            if(i != 0)
                printf(" ");
        }
        printf("\n");
    }
}

int main() {

    int n;
    scanf("%d", &n);   // Number of operations

    // Process each operation
    for(int i = 0; i < n; i++) {

        int operation;
        scanf("%d", &operation);

        if(operation == 1) {
            int value;
            scanf("%d", &value);
            push(value);          // Push operation
        }
        else if(operation == 2) {
            pop();                // Pop operation
        }
        else if(operation == 3) {
            display();            // Display operation
        }
    }

    return 0;
}