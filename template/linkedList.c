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
	if(p == NULL)  //dont have any node have id=u
		return;
	Node* tmp = makeNode(v);
	if(p==last)   //if p is last , update last is the last node
	{
		p->next=tmp;
		tmp->next=NULL;
		last=tmp;
		return;
	}
	tmp->next=p->next;
	p->next=tmp;	
		
}

void removeNode( int v)
{
	if(first==NULL) return;
	Node* prev = first;
	Node *p = NULL;
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
			prev->next=prev->next->next; 
			break;
		}
		prev = prev->next;
	}

	if(p==NULL) return;  //dont have any node have id=v to remove

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
	insertAfter(10, 13);
	printList();	
	removeNode(15);
	printList();
	return 0;	
}














