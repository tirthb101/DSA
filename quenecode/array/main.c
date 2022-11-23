#include <stdio.h>
#include <stdlib.h>

#define SIZE 25

char A[SIZE];
int front = -1, rear = -1;

void push(char z);
void pop();
void print();

int main()
{
    int temp;
    char temporary;
    while (1)
    {
        printf("1 == push, 2 == pop, 3 == front\n");
        scanf("%d", &temp);

        if (temp == 1)
        {
            scanf(" %c", &temporary);

            push(temporary);
        }
        else if (temp == 2)
        {
            pop();
        }

        print();
    }
    return 0;
}
void push(char z)
{
    if (front == rear && front == -1)
    {
        front = (front + 1) % SIZE;

        rear = (rear + 1) % SIZE;
        A[rear] = z;
    }
    else if ((rear + 1) % SIZE != front)
    {
        rear = (rear + 1) % SIZE;

        A[rear] = z;
    }
    else
    {
        printf("Overflow\n");
        exit(1);
    }
}

void pop()
{
    if (front == rear)
    {
        if (front == -1)
        {
            printf("Empty");
        }
        else
        {
            A[front] = 0;
            front = -1;
            rear = -1;
        }
    }
    else if (front != rear)
    {
        A[front] = 0;
        front = (front + 1) % SIZE;
    }
}

void print()
{
    printf("\n");
    for (size_t i = 0; i < SIZE; i++)
    {
        printf("%i ", A[i]);
    }
    printf("\n");
}