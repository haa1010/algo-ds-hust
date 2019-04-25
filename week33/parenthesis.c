#include <stdio.h>
#include <string.h>
#include<stdlib.h>
char s[50];

typedef struct Node
{
    char c;
    struct Node *next;
} Node;
Node *top;

int isEmpty()
{
    return top == NULL;
}

Node *makeNode(char x)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->c = x;
    p->next = NULL;
    return p;
}

void push(char x)
{
    Node *p = makeNode(x);
    p->next = top;
    top = p;
}

char pop()
{
    if (isEmpty())
       { printf("Stack is NULL\n"); return;}
    Node *p = top;
    char x = p->c;
    top = top->next;
    free(p);
    return x;
}
int match(char a, char b)
{
    if (a == '(' && b == ')')
        return 1;
    if (a == '[' && b == ']')
        return 1;
    if (a == '{' && b == '}')
        return 1;
    return 0;
}

int check()
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            push(s[i]);
        else
        {
            if (isEmpty())
                return 0;
            char a = pop();
            if (match(a, s[i]) == 0)
                return 0;
        }
    }
    return isEmpty();
}

int main()
{
    gets(s);
    if (check())
        printf("TRUE\n");
    else
        printf("FALSE\n");
    return 0;
}
