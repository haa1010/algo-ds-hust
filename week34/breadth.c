#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int ID;
    struct Node *leftMostChild;
    struct Node *rightSibling;
} Node;

Node *root;

Node *makeNode(int u)
{
    Node *p = (Node *)malloc(sizeof(Node)); //allocate memory for p
    p->ID = u;
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    return p;
}

Node *find(Node *r, int u)
{
    //return a pointer to a node with ID u on the tree rooted at r
    if (r == NULL)
        return NULL;
    if (r->ID == u)
        return r;
    Node *p = r->leftMostChild;
    while (p != NULL)
    {
        Node *q = find(p, u);
        if (q != NULL)
            return q;
        p = p->rightSibling;
    }
    return NULL;
}

void addChild(Node *r, int u, int x)
{
    //create a node having ID x, add this node at the end of the list of children of node with ID u
    Node *p = find(r, u);
    if (p == NULL)
        return NULL;
    Node *q = makeNode(x);
    if (p->leftMostChild == NULL)
        p->leftMostChild = q;
    else
    {
        p = p->leftMostChild;
        while (p->rightSibling != NULL)
        {
            p = p->rightSibling;
        }
        p->rightSibling = q;
    }
}

void loadDataBuildTree(char *filename)
{
    FILE *f = fopen(filename, "r");
    root = NULL;
    while (1)
    {
        int u;
        fscanf(f, "%d", &u);
        if (u == -1)
            break;
        if (root == NULL)
            root = makeNode(u);
        int k;
        fscanf(f, "%d", &k);
        for (int i = 0; i < k; i++)
        {
            int x;
            fscanf(f, "%d", &x);
            addChild(root, u, x);
        }
    }
    fclose(f);
}

void printTree(Node *r)
{
    if (r == NULL)
    {
        printf("Tree has no data\n");
        return;
    }

    printf(" %d :", r->ID);

    for (Node *p = r->leftMostChild; p != NULL; p = p->rightSibling)
    {
        printf("  %d ", p->ID);
    }
    printf("\n");
    for (Node *p = r->leftMostChild; p != NULL; p = p->rightSibling)
    {
        printTree(p);
    }
}

int main()
{
    loadDataBuildTree("INPUT");
    printTree(root);
    
    printf("\n");
    return 0;
}