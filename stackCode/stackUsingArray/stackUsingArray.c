#include <stdio.h>

#define SIZE 25

char A[SIZE];
int top = -1;

void push(char z)
{
    if (top >= SIZE - 1)
    {
        printf("Overflow");
    }
    else
    {
        top++;
        A[top] = z;
    }
}

void pop()
{
    if (top > -1)
    {
        top--;
    }
    else
    {
        printf("Underflow\n");
    }
}

char StackTop()
{
    return A[top];
}

void print()
{
    printf("\n");
    for (size_t i = 0; i <= top; i++)
    {
        printf("%c ", A[i]);
    }
    printf("\n");
}

int main()
{
    int temp;
    char temporary;
    while (1)
    {
        printf("1 == push, 2 == pop, 3 == top\n");
        scanf("%d", &temp);
        fflush(stdin);

        if (temp == 1)
        {
            scanf("%c", &temporary);
            fflush(stdin);
            push(temporary);
        }
        else if (temp == 2)
        {
            pop();
        }
        else if (temp == 3)
        {
            printf("%c\n", StackTop());
        }
        print();
    }
    return 0;
}