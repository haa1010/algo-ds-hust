#include <stdio.h>

typedef struct
{
    int coef;
    int exp;
    struct Polynom *next;
} Polynom;
void add()
{
    Polynom *PolySum, *node, *ptr, *ptr1, *ptr2;
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

int cal()
{

}