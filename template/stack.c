#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode
{
    int id;
    struct stackNode *next;
} stackNode;

typedef struct
{
    stackNode *top;
} Stack;

//initialize

Stack *stackConstuct()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    return s;
}

//check empty

int stackEmpty(Stack *s)
{
    return (s->top == NULL);
}

//check full (when out of memory)
int stackFull()
{
    printf("Cannot add more, out of memory\n");
    return 1;
}

//push : insert to top

int stackPush(Stack *s, int v)
{
    stackNode *tmp = (stackNode *)malloc(sizeof(stackNode));
    if (tmp == NULL)
    {
        stackFull();
        return 1;
    }
    tmp->id = v;
    tmp->next = s->top;
    s->top = tmp;
    return 0;
}

//pop : remove and return top item
int stackPop(Stack *s)
{
    stackNode *tmp = s->top;
    if (stackEmpty(s))
        return (int)NULL;
    int data = tmp->id;
    s->top = tmp->next;
    free(tmp);
    return data;
}

//destroy : pop all out then free
void stackDestroy(Stack *s)
{
    while (!stackEmpty(s))
    {
        stackPop(s);
    }
    free(s);
}

//print out all item in stack
void displayStack(Stack *s)
{
    stackNode *tmp = s->top;
    int data;
    if (stackEmpty(s))
        printf("Stack is empty\n");
    else
    {
        printf("Stack : ");
        {
            do
            {
                data = tmp->id;
                printf("%d | ", data);
                tmp = tmp->next;
            } while (tmp != NULL);
        }
    }
    printf("\n");
}

int main()
{
    Stack *s1 = stackConstuct();
    stackPush(s1, 10);
    stackPush(s1, 5);
    displayStack(s1);
    int a = stackPop(s1);
    int b = stackPop(s1);
    printf("a = %d ; b = %d\n", a, b);
    displayStack(s1);
    return 0;
}