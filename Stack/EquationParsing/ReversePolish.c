#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int number;
    struct Node *next;
};

struct Node *Initialize(int Value_Of_First);

void AddNode(int value_to_Add, struct Node **origin);

int main()
{
    return 0;
}

struct Node *Initialize(int value_of_First)
{
    struct Node *node = malloc(sizeof(struct Node));
    if (node == NULL)
    {
        return NULL;
    }
    node->number = value_of_First;
    node->next = NULL;
    return node;
}

void AddNode(int value_to_Add, struct Node **origin)
{
    struct Node *node = malloc(sizeof(struct Node));
    if (node == NULL)
    {
        exit(1);
    }
    node->number = value_to_Add;
    node->next = *origin;
    *origin = node;
}
