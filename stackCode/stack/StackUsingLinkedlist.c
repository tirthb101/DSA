#include <stdio.h>
#include "LinkedListFunctions.h"

void push(int value);
void pop();
void printStack();
void top();

struct node *head = NULL;

void main()
{
    return;
}

void push(int value)
{
    AddNodeHead(value, &head);
}

void pop()
{
    RemoveNodeHead(&head);
}

void top()
{
    printf("\n%d\n", getElementIndex(head, 0));
}

void printStack()
{
    printRecursive(head);
}