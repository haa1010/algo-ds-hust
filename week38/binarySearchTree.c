#include <stdio.h>
#include <stdlib.h>
int a[100];
int n;
typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
} Node;

Node *root;

Node *makeNode(int u)
{
    Node *p = (Node *)malloc(sizeof(Node)); //allocate memory for p
    p->key = u;
    p->left = NULL;
    p->right = NULL;
    return p;
}

Node* constructTree(int *index,int low, int high, int n)
{
    if(index>=n || low>high)
        return NULL;
    
}

void printTree(Node *r)
{
    if (r == NULL)
    {
        printf("Binary search tree has no data\n");
        return;
    }

    printf(" %d :", r->key);

    for (Node *p = r->left; p != NULL; p = p->right)
    {
        printf("  %d ", p->key);
    }
    printf("\n");
    for (Node *p = r->left; p != NULL; p = p->right)
    {
        printTree(p);
    }
}

int main()
{

    printTree(root);

    return 0;
}