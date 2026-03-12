/*
Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed

Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek

Output:
10
10
30
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int heap[MAX_SIZE];
int heap_size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify_up(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] > heap[index]) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else {
            break;
        }
    }
}

void heapify_down(int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    
    if (left < heap_size && heap[left] < heap[smallest]) {
        smallest = left;
    }
    
    if (right < heap_size && heap[right] < heap[smallest]) {
        smallest = right;
    }
    
    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapify_down(smallest);
    }
}

// FIXED: Ensure heapify happens on the correct index
void insert(int x) {
    if (heap_size >= MAX_SIZE) {
        return;
    }
    heap[heap_size] = x;     // Place at the end
    heapify_up(heap_size);   // Move it up to the correct spot
    heap_size++;             // THEN increment size
}

int extractMin() {
    if (heap_size <= 0) {
        return -1;
    }
    
    int min_val = heap[0];
    heap[0] = heap[heap_size - 1]; // Replace root with last element
    heap_size--;                   // Reduce size first
    
    if (heap_size > 0) {
        heapify_down(0);           // Restore heap property
    }
    
    return min_val;
}

int peek() {
    if (heap_size <= 0) {
        return -1;
    }
    return heap[0];
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;
    
    for (int i = 0; i < N; i++) {
        char op[20];
        // Added space before %s to skip any trailing whitespace or newlines
        if (scanf(" %s", op) != 1) break;
        
        if (strcmp(op, "insert") == 0) {
            int x;
            if (scanf("%d", &x) == 1) {
                insert(x);
            }
        } else if (strcmp(op, "extractMin") == 0) {
            int res = extractMin();
            printf("%d\n", res);
        } else if (strcmp(op, "peek") == 0) {
            int res = peek();
            printf("%d\n", res);
        }
    }
    
    return 0;
}