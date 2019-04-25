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

int countNode(Node *r)
{
    //return number of the nodes of tree rooted at r

    int cnt = 1;
    Node *p = r->leftMostChild;
    while (p != NULL)
    {
        cnt += countNode(p);
        p = p->rightSibling;
    }
    return cnt;
}

int countLeaves(Node *r)
{
    if (r == NULL)
        return 0;
    if (r->leftMostChild == NULL)
        return 1;
    int cnt = 0;

    Node *p = r->leftMostChild;
    while (p != NULL)
    {
        cnt += countLeaves(p);
        p = p->rightSibling;
    }

    return cnt;
}

int height(Node *r)
{
    //return the height of node r
    if (r == NULL)
        return 0;
    Node *p = r->leftMostChild;
    int h = 0;
    while (p != NULL)
    {
        int hp = height(p);
        if (hp > h)
            h = hp;
        p = p->rightSibling;
    }
    return h + 1;
}

int depth1(Node *q, int dq, int u)
{
    //compute the depth of u in the subtree rooted at q , dq is the depth of q
    if (q == NULL)
        return -1;
    if (q->ID == u)
        return dq + 1;
    Node *p = q->leftMostChild;
    while (p != NULL)
    {
        if (p->ID == u)
            return dq + 1;
        int d = depth1(p, dq + 1, u);
        if (d > 0)
            return d;
        p = p->rightSibling;
    }
    return -1;
}

int depth(Node *r, int u)
{
    //return the depth of the node ID = u of the tree rooted at r
    if (r == NULL)
        return 0;
    Node *p = find(root, 4);
    return depth1(p, 1, u);
}

void preOrder(Node *r)
{
    if (r == NULL)
        return;
    printf("%d ", r->ID);
    Node *p = r->leftMostChild;
    while (p != NULL)
    {
        preOrder(p);
        p = p->rightSibling;
    }
}

void inOrder(Node *r)
{
    if (r == NULL)
        return;
    inOrder(r->leftMostChild);
    printf("%d ", r->ID);
    if (r->leftMostChild == NULL)
        return;
    Node *p = r->leftMostChild->rightSibling;
    while (p != NULL)
    {
        inOrder(p);
        p = p->rightSibling;
    }
}

void postOrder(Node *r)
{
    if (r == NULL)
        return;
    Node *p = r->leftMostChild;
    while (p != NULL)
    {
        postOrder(p);
        p = p->rightSibling;
    }
    printf("%d ", r->ID);
}

int main()
{
    loadDataBuildTree("INPUT");
    printTree(root);
    printf("node %d\n", countNode(root));
    printf("leaves %d\n", countLeaves(root));
    printf("depth of %d is %d\n", 10, depth(root, 10));
    Node *p = find(root, 7);
    printf("height of 7 is  %d\n", height(p));
    printf("Pre  : ");
    preOrder(root);
    printf("\n");
    printf("In   : ");
    inOrder(root);
    printf("\n");
    printf("Post : ");
    postOrder(root);
    printf("\n");
    return 0;
}