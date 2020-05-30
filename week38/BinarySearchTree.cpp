#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
} Node;

Node *makeNode(int key)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->left = NULL;
    p->right = NULL;
    return p;
}
Node *root = NULL;
Node *makeTree(Node *r, int key)
{
    if (r == NULL)
    {
        r = makeNode(key);
    }
    else if (key < r->key)
        r->left = makeTree(r->left, key);
    else if (key > r->key)
        r->right = makeTree(r->right, key);
    return r;
}

void printTree(Node *r)
{
    if (r == NULL)
        return;
    printTree(r->left);
    printf("%d\t", r->key);
    printTree(r->right);
}

Node *search(Node *r, int k)
{
    if (r == NULL)
    {
        return NULL;
    }
    else
    {
        if (r->key == k)
            return r;
        if (r->key > k)
            return search(r->left, k);
        else
            return search(r->right, k);
    }
}

Node *searchParent(Node *r, int k)
{
    if (r == NULL)
    {
        return NULL;
    }
    else
    {
        if (r->left->key == k || r->right->key == k)
            return r;
        else if (r->key > k)
            return searchParent(r->left, k);
        else if (r->key < k)
            return searchParent(r->right, k);
    }
}

Node *findMin(Node *r)
{
    if (r == NULL)
        return NULL;
    else
    {
        if (r->left == NULL)
            return r;
        else
            return findMin(r->left);
    }
}

Node *findMax(Node *r)
{
    if (r == NULL)
        return NULL;
    else
    {
        if (r->right == NULL)
            return r;
        else
            return findMax(r->right);
    }
}

Node *successor(Node *r)
{
    if (r->right != NULL)
        return findMin(r->right);
    Node *p = searchParent(root, r->key);
    while (p != NULL && p->right->key == r->key)
    {
        r = p;
        p = searchParent(root, p->key);
    }
    return p;
}

Node *predecessor(Node *r)
{
    if (r->left != NULL)
        return findMax(r->left);
    Node *p = searchParent(root, r->key);
    while (p != NULL && p->left->key == r->key)
    {
        r = p;
        p = searchParent(root, p->key);
    }
    return p;
}

Node *deleteNode(Node *r, int k)
{
    if (r == NULL)
        return r;
    if (r->key > k)
        r->left = deleteNode(r->left, k);
    else if (r->key < k)
        r->right = deleteNode(r->right, k);

    else
    {
        if (r->left == NULL)
        {
            Node *tmp = r->right;
            free(r);
            return tmp;
        }
        else if (r->right == NULL)
        {
            Node *tmp = r->left;
            free(r);
            return tmp;
        }

        Node *p = findMin(r->right);
        r->key = p->key;
        r->right = deleteNode(r->right, p->key);
    }
    return r;
}

void inputData(char *fileName)
{
    FILE *f = fopen(fileName, "r");
    int n;
    fscanf(f, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        int key;
        fscanf(f, "%d", &key);
        if (root == NULL)
            root = makeNode(key);
        else
        {
            makeTree(root, key);
        }
    }
}

int main()
{
    inputData("input.txt");
    printTree(root);
    Node *a = search(root, 35);
    if (a == NULL)
        printf("\nNo result\n");
    else
    {
        printf("\nsearch: %d", a->key);
        if (a->left != NULL)
            printf("\nsearch left : %d", a->left->key);
        if (a->right != NULL)
            printf("\nsearch right: %d", a->right->key);
    }
    printf("\n find min %d \n", findMin(root)->key);

    successor int k;
    scanf("%d", &k);
    Node *r = search(root, k);
    if (r == NULL)
        printf("Node key = k doesnt exist\n");
    else
    {
        printf("successor of %d is %d\n", k, successor(r)->key);
        printf("predecessor of %d is %d\n", k, predecessor(r)->key);
    }
    deleteNode(root, 35);
    printTree(root);
    return 0;
}
