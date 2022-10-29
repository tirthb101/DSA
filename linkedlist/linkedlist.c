#include <stdio.h>
#include "LinkedListFunctions.h"

int main(void)
{
    struct node *head = NULL;
    for (int i = 0; i < 10; i++)
    {
        AddNodeHead(i * i * i, &head);
    }
    // You can use any functions from LinkedListFunctions
    printRecursiveReverse(head);

    return 0;
}
