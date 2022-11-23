#include <stdio.h>
#include <stdlib.h>

#define size 2

char stack[size];
int top = -1;

int isempty();
int isfull();
int pop();
void push();

void main()
{
    char input[25], output[25];
    int inputIndex = 0, outputIndex = 0;
}

int pop()
{
    if (!isempty())
    {
        int item = stack[top];
        top--;
        return item;
    }
    printf("stack is empty\n");
    exit(1);
}

void push(int a)
{
    if (!isfull())
    {
        top++;
        stack[top] = a;
        return;
    }
    printf("stack is full\n");
    exit(1);
}

int isempty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}

int isfull()
{
    if (top >= size - 1)
    {
        return 1;
    }
    return 0;
}