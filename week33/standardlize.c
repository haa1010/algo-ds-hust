#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int k, cnt = 0;
int a1[1000], a2[1000];
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
    for (int i = 0; i < k; i++)
    {
        addLast(a1[i], a2[i]);
    }
}

void sorting()
{
    for (Node *p = first; p != NULL; p = p->next)
    {
        for (Node *pj = p->next; pj != NULL; pj = pj->next)
        {
            if (pj->po > p->po)
            {
                int tmp = p->po;
                p->po = pj->po;
                pj->po = tmp;
                //exponent;
                tmp = p->co;
                p->co = pj->co;
                pj->co = tmp;
            }
        }
    }
}

void standarlize()
{
    if (first == NULL)
        return;
    sorting();
    Node *e = first;
    while (e != NULL)
    {

        int coef = e->co;
        int power = e->po;
        Node *ne = e->next;
        while (ne != NULL)
        {
            if (ne->po == e->po)
            {
                coef += ne->co;
                ne = ne->next;
            }
            else
                break;
        }
        e = ne;

        Node *ans = makeNode(coef, power);
       
        if (first_result == NULL)
            first_result = ans;
        else
            last_result->next = ans;
        last_result = ans;
        cnt++;
    }
}

void printList(FILE *fout)
{
    for (Node *p = first_result; p != NULL; p = p->next)
    {
        fprintf(fout, "%d \t", p->co);
    }
    fprintf(fout, "\n");
    for (Node *p = first_result; p != NULL; p = p->next)
    {
        fprintf(fout, "%d \t", p->po);
    }
    fprintf(fout, "\n");
}

int main()
{
    int i;
    FILE *f = fopen("STDPOLY.INP", "r");
    FILE *fout = fopen("STDPOLY.OUT", "w");
    fscanf(f, "%d ", &k);
    for (i = 0; i < k; i++)
        fscanf(f, "%d", &a1[i]);
    for (i = 0; i < k; i++)
        fscanf(f, "%d", &a2[i]);
    addData();
    standarlize();
    fprintf(fout, "%d\n", cnt);
    printList(fout);
    fclose(f);
    fclose(fout);
    return 0;
}