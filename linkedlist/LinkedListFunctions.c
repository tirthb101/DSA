#include <stdio.h>
#include <stdlib.h>
#include "LinkedListFunctions.h"

struct node *getanode(int z)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    if (newNode == NULL)
    {
        exit(1);
    }

    newNode->data = z;
    newNode->next = NULL;
    return newNode;
}

void AddNodeHead(int value, struct node **head)
{
    struct node *newNode = getanode(value);
    newNode->next = *head;
    *head = newNode;
}

void print(struct node *head)
{
    if (head == NULL)
    {
        printf("\nList is empty, Function called was print.\n");
        return;
    }
    printf("\n");
    printf("------------------------------------------\n");
    while (head->next != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("%d", head->data);
    printf("\n------------------------------------------\n");
}

void RemoveNodeHead(struct node **head)
{
    if (*head == NULL)
    {
        printf("\nList is empty, Couldn't Remove Node from Head.\n");
        return;
    }
    struct node *ptrDeleted = *head;
    *head = ptrDeleted->next;
    free(ptrDeleted);
}

void printRecursive(struct node *head)
{
    if (head == NULL)
    {
        printf("\n");
        return;
    }
    printf("%d ", head->data);
    printRecursive(head->next);
}

void printRecursiveReverse(struct node *head)
{
    if (head == NULL)
    {
        printf("\n");
        return;
    }
    printRecursiveReverse(head->next);
    printf("%d ", head->data);
}

void reverse(struct node **head)
{
    struct node *current, *prev = NULL, *next;
    next = (**head).next;
    current = *head;
    while (current != NULL)
    {
        current->next = prev;
        prev = current;
        current = next;
        if (next != NULL)
        {

            next = current->next;
        }
    }
    *head = prev;
}

void reverseRecursion(struct node *node, struct node **nodeptr)
{
    // Returns new head , Takes as input first node and pointer to variable which stores head
    if (node->next == NULL)
    {
        *nodeptr = node;
        return;
    }
    reverseRecursion(node->next, nodeptr);
    node->next->next = node;
    node->next = NULL;
}

void insertAtIndex(struct node *head, int index, int value)
{
    int i = 0;
    while (head != NULL && i < index - 1)
    {
        head = head->next;
        i++;
    }
    if (head == NULL || head->next == NULL)
    {
        printf("Index out of range, Function called removeAtIndex.\n");
        exit(1);
    }
    struct node *newNode = getanode(value);
    newNode->next = head->next;
    head->next = newNode;
}

void removeAtIndex(struct node *head, int index)
{

    int i = 0;
    while (head != NULL && i < index - 1)
    {
        head = head->next;
        i++;
    }
    if (head == NULL || head->next == NULL)
    {
        printf("Index out of range, Function called removeAtIndex.\n");
        exit(1);
    }
    struct node *q = head->next;
    head->next = q->next;
    free(q);
}

int getElementIndex(struct node *head, int index)
{
    int i = 0;
    while (head != NULL && i < index)
    {
        head = head->next;
        i++;
    }
    if (head == NULL)
    {
        printf("Index out of range, Function called getElementIndex.\n");
        exit(1);
    }
    return head->data;
}