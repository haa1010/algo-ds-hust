#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int id;
	struct Node* next;
}Node;

Node* first;
Node* last;

Node* makeNode(int v)
{
	Node* p = (Node*) malloc( sizeof(Node));  //allocate memory for p 
	p->id = v;
	p->next = NULL;
	return p;
}

void addLast( int v)
{
	Node* p = makeNode(v);
	if(last!=NULL)
		last->next=p;
	last = p;
	if(first==NULL)
		first=p;
}

void addFirst( int v)
{
	Node* p = makeNode(v);
	p->next = first;
	first  = p;
	if(last==NULL)
		last = p;
}

void insertAfter(int u, int v)
{
 //create a newnode have id = v
	//insert after the node with with id = u
	Node* p = first;
	while(p!= NULL){
		if(p->id==u)
			break;
		p=p->next;
	}
	if(p == NULL)
		return;
	Node* tmp = makeNode(v);
	tmp->next=p->next;
	p->next=tmp;	
}

void removeNode( int v)
{
	Node* prev = first;
	Node* p = makeNode(v);
	if(prev->id==v)
	{
		first=prev->next;
		free(prev);
		return;
	}
	while(prev!=NULL)
	{
		if(prev->next != NULL && prev->next->id==v)
		{
			p = prev->next; 
			break;
		}
		prev=prev->next;
	}
	prev->next=p->next;
	free(p);
}

void printList()
{
	for(Node* p  =first; p != NULL; p=p->next)
		printf("%d ",p->id);
	printf("\n");
}

int main()
{
	for( int i = 1 ; i <= 10 ; i++)
		addLast(i);
	printList();
	insertAfter(5, 13);
	printList();	
	removeNode(10);
	printList();
	return 0;	
}














