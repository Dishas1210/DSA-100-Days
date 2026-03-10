#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

/* Check if deque is empty */
int empty() {
    return (front == -1);
}

/* Return size */
int size() {
    if (empty()) return 0;
    return rear - front + 1;
}

/* Insert at front */
void push_front(int value) {
    if (front == -1) {
        front = rear = 0;
    }
    else if (front == 0) {
        printf("Overflow\n");
        return;
    }
    else {
        front--;
    }

    deque[front] = value;
}

/* Insert at rear */
void push_back(int value) {
    if (rear == MAX - 1) {
        printf("Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    }
    else {
        rear++;
    }

    deque[rear] = value;
}

/* Remove from front */
void pop_front() {
    if (empty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Removed: %d\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    }
    else {
        front++;
    }
}

/* Remove from rear */
void pop_back() {
    if (empty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Removed: %d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    }
    else {
        rear--;
    }
}

/* Get front element */
void get_front() {
    if (empty())
        printf("Deque is empty\n");
    else
        printf("Front: %d\n", deque[front]);
}

/* Get rear element */
void get_back() {
    if (empty())
        printf("Deque is empty\n");
    else
        printf("Rear: %d\n", deque[rear]);
}

/* Clear deque */
void clear() {
    front = rear = -1;
}

/* Display deque */
void display() {
    if (empty()) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", deque[i]);

    printf("\n");
}

/* Reverse deque */
void reverse() {
    if (empty()) return;

    int i = front, j = rear, temp;

    while (i < j) {
        temp = deque[i];
        deque[i] = deque[j];
        deque[j] = temp;
        i++;
        j--;
    }
}

int main() {

    push_back(10);
    push_back(20);
    push_front(5);

    display();

    get_front();
    get_back();

    pop_front();
    pop_back();

    display();

    printf("Size: %d\n", size());

    return 0;
}