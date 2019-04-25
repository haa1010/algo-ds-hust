#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int e;
    int a;
	struct Node* next;
}Node;


Node* first;
Node* last;

Node* makeNode(int value1, int value2)
{
	Node* p = (Node*) malloc( sizeof(Node));  //allocate memory for p 
	p->e = value1;
    p->a = value2;
	p->next = NULL;
	return p;
}


void addLast( int value1, int value2)
{
	Node* p = makeNode(value1, value2);
	if(last!=NULL)
		last->next=p;
	last = p;
	if(first==NULL)
		first=p;
}

double compute(  Node* p , double v)
{
    double ans=0.0;
	Node* p = first;
	for(Node* p  =first; p != NULL; p=p->next) 
		{
			ans += p->a * pow(v, (p->e));	
		}
	return ans;
}
int main()
{
    scanf("%d",&n);

    //add data
    for()
    printf("Result = %.2f\n", res(first, v));
    return 0;
}

