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

int depth1(Node *q, int dq, int u)
{
    //compute the depth of u in the subtree rooted at q , dq is the depth of q
    if (q == NULL)
        return -1;
    if (q->ID == u)
        return dq;
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
    return depth1(r, 1, u);
}

int sum = 0;
int sumDepth(Node *r)
{
    //post
    if (r == NULL)
        return;
    Node *p = r->leftMostChild;
    while (p != NULL)
    {
        sumDepth(p);
        p = p->rightSibling;
    }
    printf("depth of %d is %d\n", r->ID, depth(root, r->ID));
    sum += depth(root, r->ID);
    return sum;

    //preorder
    // if (r == NULL)
    //     return;
    // printf("depth of %d is %d\n", r->ID, depth(root, r->ID));
    // sum += depth(root, r->ID);
    // Node *p = r->leftMostChild;
    // while (p != NULL)
    // {
    //     sumDepth(p);
    //     p = p->rightSibling;
    // }
    // return sum;

    //inorder

    // if (r == NULL)
    //     return;
    // sumDepth(r->leftMostChild);
    // printf("depth of %d is %d\n", r->ID, depth(root, r->ID));
    // sum+=depth(root,r->ID);
    //     if (r->leftMostChild == NULL)
    //     return;
    // Node *p = r->leftMostChild->rightSibling;
    // while (p != NULL)
    // {
    //     sumDepth(p);
    //     p = p->rightSibling;
    // }
    // return sum;

}

int main()
{
    loadDataBuildTree("INPUT");
    printf("Sum depth is %d \n", sumDepth(root));
    return 0;
}