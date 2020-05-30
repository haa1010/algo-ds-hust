#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_L_WORD 100
#define MAX_SZ 10000
#define MAX_T 100

typedef struct Node
{
    char *key;
    int count;
    struct Node *left;
    struct Node *right;
} Node;

Node *bst[MAX_T];

Node *makeNode(char *k)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = (char *)malloc(strlen(k) + 1);
    sprintf(p->key, "%s", k);
    p->left = NULL;
    p->right = NULL;
    p->count = 1;
    return p;
}

Node *find(Node *r, char *k)
{
    if (r == NULL)
        return NULL;
    int c = strcmp(k, r->key);
    if (c == 0)
        return r;
    if (c > 0)
        return find(r->right, k);
    return find(r->left, k);
}

Node *insert(Node *r, char *k)
{
    if (r == NULL)
        return makeNode(k);
    int c = strcmp(k, r->key);
    if (c < 0)
        r->left = insert(r->left, k);
    else
        r->right = insert(r->right, k);
    return r;
}

void freeBST(Node *r)
{
    if (r == NULL)
        return;
    freeBST(r->left);
    freeBST(r->right);
    free(r->key);
    free(r);
    r = NULL;
}

void initDict()
{
    for (int i = 0; i < MAX_T; i++)
        bst[i] = NULL;
}

void freeDict()
{
    for (int i = 0; i < MAX_T; i++)
        free(bst[i]);
}

void normalize(char *t)
{
    if (t[strlen(t) - 1] == 10)
        t[strlen(t) - 1] == '\0';
}

int ignoreChar(int c)
{
    if (c == ' ' || c == '\t' || c == '.' || c == ',' || c == '\n')
        return 1;
    return 0;
}

int hashCode(char *s)
{
    int h = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        h = ((h * 256) % MAX_T + s[i]) % MAX_T;
    }
    if (h < 0)
        h = -h;
    return h;
}

void printBST(Node *r)
{
    if (r == NULL)
        return;
    printBST(r->left);
    printf("%s : %d times\n", r->key, r->count);
    printBST(r->right);
}

void print()
{
    for (int h = 0; h < MAX_T; h++)
    {
        if (bst[h] != NULL)
            printBST(bst[h]);
        else
            printf("-------------------------h = %d \n", h);
    }
}

int contain(char *s, char c)
{
    for (int i = 0; i < strlen(s); i++)
        if (s[i] == c)
            return 1;
    return 0;
}

void solveFile(char *filename)
{
    initDict();
    FILE *f = fopen(filename, "r");
    char s[MAX_SZ];
    while (!feof(f))
    {
        fgets(s, sizeof s, f);
        normalize(s);
        if (contain(s, '#'))
            break;
        int i = 0;
        char str[MAX_L_WORD];
        while (i < strlen(s))
        {
            while (i < strlen(s) && ignoreChar(s[i]))
                i++;
            if (i >= strlen(s))
                break;
            int j = 0;
            while (i < strlen(s) && !ignoreChar(s[i]))
            {
                str[j] = s[i];
                j++;
                i++;
            }
            str[j] = '\0';
            int h = hashCode(str);
            printf("got new word %s\t length = %ld\t h=%d\n", str, strlen(str), h);
            Node *p = find(bst[h], str);
            if (p != NULL)
                p->count = p->count + 1;
            else
                bst[h] = insert(bst[h], str);
        }
    }

    fclose(f);
    print();
    freeDict();
}

int main()
{
    char *fi = "input";
    solveFile(fi);
}
