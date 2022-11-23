#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void InOrder(struct node *root);
void PostOrder(struct node *root);
void PreOrder(struct node *root);
struct node *Getanode(int data);
struct node *Insert(struct node *root, int data);
struct node *maxnum(struct node *root);
struct node *min(struct node *root);
int max(int a, int b);
int Height(struct node *root);
struct node *InOrderSuccesor(struct node *root, int data);
struct node *delete (struct node *root, int data);
struct node *findNode(struct node *root, int data);
bool isBst(struct node *root);
bool isbstlesser(struct node *root, int data);
bool isbstgreater(struct node *root, int data);

bool isbstv2(struct node *root);
bool isbstutilv2(struct node *root, int minvalue, int maxvalue);

void main()
{
    struct node *root = NULL;
    root = Insert(root, 12);
    root = Insert(root, 5);
    root = Insert(root, 15);
    root = Insert(root, 3);
    root = Insert(root, 7);
    root = Insert(root, 13);
    root = Insert(root, 17);
    root = Insert(root, 1);
    root = Insert(root, 9);
    root = Insert(root, 20);
    root = Insert(root, 8);
    root = Insert(root, 11);
    root = Insert(root, 18);

    printf("%d \n", (int)isbstv2(root));

    InOrder(root);
    printf("\n");
}

struct node *Insert(struct node *root, int data)
{
    if (root == NULL)
    {
        root = Getanode(data);
    }
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

void InOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);
}
void PostOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ", root->data);
}

void PreOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

struct node *Getanode(int data)
{
    struct node *node = malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct node *maxnum(struct node *root)
{
    if (root->right == NULL)
    {
        return root;
    }
    return maxnum(root->right);
}

struct node *min(struct node *root)
{
    if (root->left == NULL)
    {
        return root;
    }
    return min(root->left);
}

int Height(struct node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int maxHeight = max(Height(root->left), Height(root->right)) + 1;
    return maxHeight;
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

struct node *delete (struct node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if (data < root->data)
    {
        root->left = delete (root->left, data);
    }
    else if (data > root->data)
    {
        root->right = delete (root->right, data);
    }
    else
    {
        // If no child
        if (root->left == root->right && root->left == NULL)
        {
            free(root);
            root == NULL;
        }
        else if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            root = temp;
        }

        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            root = temp;
        }
        else
        {
            struct node *temp = maxnum(root->left);
            root->data = temp->data;
            root->left = delete (root->left, root->data);
        }

        return root;
    }
}
struct node *findNode(struct node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data == data)
    {
        return root;
    }
    else if (data < root->data)
    {
        return findNode(root->left, data);
    }
    else
    {
        return findNode(root->right, data);
    }
}

struct node *InOrderSuccesor(struct node *head, int data)
{
    struct node *ancestor = head;
    struct node *current = findNode(head, data);

    if (head == NULL || current == NULL)
    {
        printf("couldnt find\n");
        return head;
    }
    if (current->right != NULL)
    {
        return min(current->right);
    }
    else
    {
        while (ancestor->left != current && ancestor->right != current)
        {
            if (data < ancestor->data && ancestor->left != current)
            {
                ancestor = ancestor->left;
            }
            else if (ancestor->right != current)
            {
                ancestor = ancestor->right;
            }
        }

        return ancestor;
    }
}

bool isBst(struct node *root)
{
    if (root == NULL)
    {
        return true;
    }
    else if (isbstlesser(root->left, root->data) && isbstgreater(root->right, root->data) && isBst(root->right) && isBst(root->left))
    {
        return true;
    }
    return false;
}

bool isbstlesser(struct node *root, int data)
{
    if (root == NULL)
    {
        return true;
    }
    else if (root->data <= data && isbstlesser(root->left, data) && isbstlesser(root->right, data))
    {
        return true;
    }
    return false;
}

bool isbstgreater(struct node *root, int data)
{
    if (root == NULL)
    {
        return true;
    }
    else if (root->data > data && isbstgreater(root->left, data) && isbstgreater(root->right, data))
    {
        return true;
    }
    return false;
}

bool isbstv2(struct node *root)
{
    return isbstutilv2(root, INT_MIN, INT_MAX);
}

bool isbstutilv2(struct node *root, int minvalue, int maxvalue)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data <= maxvalue && root->data > minvalue && isbstutilv2(root->left, minvalue, root->data) && isbstutilv2(root->right, root->data, maxvalue))
    {
        return true;
    }
    return false;
}