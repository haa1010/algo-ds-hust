#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int k;
int a1[1000], a2[1000];
int ans[1000] = {0};
typedef struct Node
{
    int co;
    int po;
    struct Node *next;
} Node;

Node *first, *last;
Node *first_result, *last_result;

Node *makeNode(int a1, int a2)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->co = a1;
    p->po = a2;
    p->next = NULL;
    return p;
}

void addLast(int a1, int a2)
{
    Node *p = makeNode(a1, a2);
    if (last != NULL)
        last->next = p;
    last = p;
    if (first == NULL)
        first = p;
}

void addData()
{
    for (int i = 0; i <= k; i++)
    {
        addLast(a1[i], a2[i]);
    }
}

int poly()
{
    int cnt = 0;
    for (Node *p = first; p->next != NULL; p = p->next)
    {
        int i = p->po;
        ans[i] = ans[i] + p->co;
    }
    for (int i = k; i > 0; i--)
        if (ans[i] != 0)
            cnt++;
    return cnt;
}
int main()
{
    int i;
    FILE *f = fopen("STDPOLY.txt", "r");
    fscanf(f, "%d ", &k);
    for (i = 0; i < k; i++)
        fscanf(f, "%d", &a1[i]);
    for (i = 0; i < k; i++)
        fscanf(f, "%d", &a2[i]);
    addData();

    printf("%d\n", poly());

    for (int i = k; i > 0; i--)
    {
        if (ans[i] != 0)
            printf("%d \t ", ans[i]);
    }
    printf("\n");
    for (int i = k; i > 0; i--)
    {
        if (ans[i] != 0)
            printf("%d \t ", i);
    }
    fclose(f);
    return 0;
}