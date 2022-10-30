#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "LinkedListFunctions.h"

void push(int value);
void pop();
void printStack();
int top();
bool isEmpty();

struct node *head = NULL;

void main()
{
    char *A = "String";

    for (int i = 0; i < strlen(A); i++)
    {
        push(A[i]);
    }
    printf("\n");
    while (!isEmpty())
    {
        printf("%c", top());
        pop();
    }
    printf("\n");

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

int top()
{
    return getElementIndex(head, 0);
}

bool isEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    return false;
}

void printStack()
{
    printRecursive(head);
}