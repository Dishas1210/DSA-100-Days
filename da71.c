#include <stdio.h>
#include <string.h>

#define SIZE 100

int hashTable[SIZE];

void init() {
    for(int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

void insert(int key, int m) {
    int index = key % m;

    for(int i = 0; i < m; i++) {
        int newIndex = (index + i*i) % m;

        if(hashTable[newIndex] == -1) {
            hashTable[newIndex] = key;
            return;
        }
    }
}

int search(int key, int m) {
    int index = key % m;

    for(int i = 0; i < m; i++) {
        int newIndex = (index + i*i) % m;

        if(hashTable[newIndex] == key)
            return 1;

        if(hashTable[newIndex] == -1)
            return 0;
    }
    return 0;
}

int main() {
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);

    init();

    char op[10];
    int key;

    for(int i = 0; i < n; i++) {
        scanf("%s %d", op, &key);

        if(strcmp(op, "INSERT") == 0) {
            insert(key, m);
        } else if(strcmp(op, "SEARCH") == 0) {
            if(search(key, m))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}