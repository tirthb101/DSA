#include <stdio.h>
#include <stdlib.h>
#include "LinkedListFunctions.h"

struct node *head = NULL;
struct node *tail = NULL;

void push(int z);
int pop();

void main()
{
    push(1);
    push(2);
    push(6);
    printf("%d\n", pop());
    push(100);
}

void push(int z)
{
    struct node *newNode = getanode(z);

    if (head == tail && head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

int pop()
{
    if (head == NULL)
    {
        printf("Quene is empty.\n");
        exit(1);
    }
    int value = head->data;
    struct node *oldNode = head;
    head = head->next;
    free(oldNode);
    return value;
}