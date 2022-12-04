#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *Insert(Node *root, int data);
void InOrder(Node *root);
Node *Getanode(int data);
Node *LevelOrder(Node *root);

int main()
{
    Node *root = NULL;
    root = Insert(root, 5);
    root = Insert(root, 2);
    root = Insert(root, 3);
    root = Insert(root, 1);
    root = Insert(root, 7);

    InOrder(root);
    cout << endl;
    LevelOrder(root);
    cout << "hello";
}
void InOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);
}

Node *Getanode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node *Insert(Node *root, int data)
{
    if (root == NULL)
    {
        root = Getanode(data);
    }
    else if (data < root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}
Node *LevelOrder(Node *root)
{
    queue<Node *> q;
    Node *temp;
    q.push(root);

    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }

        cout << temp->data << " ";
    }

    cout << "\n";
}