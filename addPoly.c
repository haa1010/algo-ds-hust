#include <stdio.h>

typedef struct
{
    int coef;
    int exp;

    struct Polynom *next;
} Polynom;
  Polynom *PolySum, *node, *ptr, *ptr1, *ptr2, *Poly1, *Poly2;
Node *makeNode(int co, int ex)
{
    Node *p = (Node *)malloc(sizeof(Node)); //allocate memory for p
    p->coef = co;
    p->exp = ex;
    p->next = NULL;
    return p;
}

void addLast(int co , int ex, node* last, node* first)
{
    Node *p = makeNode(co,ex);
    if (last != NULL)
        last->next = p;
    last = p;
    if (first == NULL)
        first = p;
   
}

void add()
{
  
    Polynom *node = (Polynom *)malloc(sizeof(Polynom));
    PolySum = node;
    ptr1 = Poly1;
    ptr2 = Poly2;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        ptr = node;
        if (ptr1->exp < ptr2->exp)
        {
            node->coef = ptr2->coef;
            node->exp = ptr2->exp;
            ptr2 = ptr2->next;
            //update ptr list 2
        }
        else if (ptr1->exp > ptr2->exp)
        {
            node->coef = ptr1->coef;
            node->exp = ptr1->exp;
            ptr1 = ptr1->next;
            //update ptr list 1
        }
        else
        {
            node->coef = ptr2->coef + ptr1->coef;
            node->exp = ptr2->exp;
            ptr1 = ptr1->next;
            //update ptr list 1
            ptr2 = ptr2->next;
            //update ptr list 2
        }

        node = (Polynom *)malloc(sizeof(Polynom));
        ptr->next = node;
    }

    if (ptr1 == NULL)
    {
        while (ptr2 != NULL)
        {
            node->coef = ptr2->coef;
            node->exp = ptr2->exp;
            ptr2 = ptr2->next;
            ptr = node;
            node = (Polynom *)malloc(sizeof(Polynom));
            ptr->next = node;
        }
    }
    else if (ptr2 == NULL)
    {
        while (ptr1 != NULL)
        {
            node->coef = ptr1->coef;
            node->exp = ptr1->exp;
            ptr2 = ptr1->next;
            ptr = node;
            node = (Polynom *)malloc(sizeof(Polynom));
            ptr->next = node;
        }
    }
    ptr->next = NULL;
}

void printList()
{
    for (Node *p = first; p != NULL; p = p->next)
        printf("%d ", p->id);
    printf("\n");
}
int main()
{
    node* poly1
    printf("- Enter polynomial 1 ");
    printf("Enter all polynomial 1's coefficients-exponents :");
    for (int j = 0; j < 3; j++)
    {
        int temp1, temp2;
        scanf("%d %d", &temp1, &temp2);
        addLast(temp1, temp2);
    }
    printf("- Enter polynomial 2 ");
    printf("Enter all polynomial 2's coefficients-exponents :");
    for (int j = 0; j < 3; j++)
    {
        int temp1, temp2;
        scanf("%d %d", &temp1, &temp2);
        addLast(temp1, temp2);
    }
}