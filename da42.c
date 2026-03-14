#include <stdio.h>
#include <string.h>

#define MAX 100

int pq[MAX];
int size = 0;

/* Function to insert element into priority queue */
void insert(int value)
{
    if(size == MAX)
        return;

    pq[size++] = value;
}

/* Function to delete highest priority element (smallest value) */
void deleteElement()
{
    if(size == 0)
    {
        printf("-1\n");
        return;
    }

    int minIndex = 0;

    for(int i = 1; i < size; i++)
    {
        if(pq[i] < pq[minIndex])
            minIndex = i;
    }

    printf("%d\n", pq[minIndex]);

    for(int i = minIndex; i < size - 1; i++)
        pq[i] = pq[i + 1];

    size--;
}

/* Function to peek highest priority element */
void peek()
{
    if(size == 0)
    {
        printf("-1\n");
        return;
    }

    int min = pq[0];

    for(int i = 1; i < size; i++)
    {
        if(pq[i] < min)
            min = pq[i];
    }

    printf("%d\n", min);
}

int main()
{
    int n;
    scanf("%d", &n);

    while(n--)
    {
        char operation[10];
        scanf("%s", operation);

        if(strcmp(operation, "insert") == 0)
        {
            int x;
            scanf("%d", &x);
            insert(x);
        }
        else if(strcmp(operation, "delete") == 0)
        {
            deleteElement();
        }
        else if(strcmp(operation, "peek") == 0)
        {
            peek();
        }
    }

    return 0;
}