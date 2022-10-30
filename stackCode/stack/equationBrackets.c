#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "LinkedListFunctions.h"

void push(int value);
void pop();
void printStack();
int top();
bool isEmpty();
int priority(char a);

struct node *head = NULL;

void main()
{
    char input[25], output[26] = "";
    int outputIndex = -1;
    scanf("%s", input);
    AddNodeHead('$', &head);

    for (int i = 0; i < strlen(input); i++)
    {
        if (priority(input[i]) == 5)
        {
            output[++outputIndex] = input[i];
        }
        else
        {
            if (priority(input[i]) != 0)
            {
                while (priority((char)top()) >= priority(input[i]) && (char)top() != '(')
                {
                    output[++outputIndex] = (char)top();
                    pop();
                }
                push(input[i]);
            }
            else if (input[i] == '(')
            {
                push(input[i]);
            }
            else if (input[i] == ')')
            {
                while (!isEmpty() && (char)top() != '(')
                {
                    output[++outputIndex] = (char)top();
                    pop();
                }
                pop();
            }
        }
    }
    while (!isEmpty())
    {

        if ((char)top() != '(' && (char)top() != ')')
        {
            output[++outputIndex] = (char)top();
        }
        pop();
    }

    output[outputIndex] = '\0';
    puts(output);

    return;
}

int priority(char a)
{
    switch (a)
    {
    case '*':
        return 4;
        break;

    case '/':
        return 4;
        break;

    case '+':
        return 3;
        break;
    case '-':
        return 3;
        break;
    case '(':
        return 0;
        break;
    case ')':
        return 0;
        break;
    case '$':
        return 0;
        break;

    default:
        return 5;
        break;
    }
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