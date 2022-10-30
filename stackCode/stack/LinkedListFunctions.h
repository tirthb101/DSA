struct node
{
    int data;
    struct node *next;
};

void print(struct node *head);
struct node *getanode(int value);
void AddNodeHead(int value, struct node **head);
void RemoveNodeHead(struct node **head);
void printRecursive(struct node *head);
void printRecursiveReverse(struct node *head);
void reverse(struct node **head);
void reverseRecursion(struct node *node, struct node **nodeptr);
void insertAtIndex(struct node *head, int index, int value);
void removeAtIndex(struct node *head, int index);
int getElementIndex(struct node *head, int index);
