#include <stdio.h>

#define MAX 100

int main() {
    int q[MAX];
    int front = 0, rear = -1;
    int n, m, i, x;

    scanf("%d", &n);

    // enqueue
    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        rear = (rear + 1) % MAX;
        q[rear] = x;
    }

    scanf("%d", &m);

    // circular rotation (dequeue + enqueue)
    for(i = 0; i < m; i++) {
        x = q[front];                // element removed
        front = (front + 1) % MAX;   // dequeue

        rear = (rear + 1) % MAX;     // enqueue again
        q[rear] = x;
    }

    // print n elements from front
    for(i = 0; i < n; i++) {
        printf("%d ", q[(front + i) % MAX]);
    }

    return 0;
}