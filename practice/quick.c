#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
    struct node *plink;
}node;
struct node *first=NULL, *last=NULL;


node* makenode(int v)
{
	node* p = (node*) malloc( sizeof(node));  //allocate memory for p 
	p->id = v;
	p->next = NULL;
	return p;
}

void printList()
{
	for(Node* p  =first; p != NULL; p=p->next)
		printf("%d ",p->id);
	printf("\n");
}

void addLast( int v)
{
	node* p = makenode(v);
	if(last!=NULL)
		last->next=p;
	last = p;
	if(first==NULL)
		first=p;
}

void swap(struct node* a,struct node* b)
{
    int temp;
    temp=a->data;
    a->data=b->data;
    b->data=temp;
}
 
void qsort(struct node *low, struct node *high)
{
    if(low==NULL || high==NULL || low == high || low->plink == high)
    return ;
 
    struct node *pivot=low, *tmp=low->link;
    while(tmp != high->link)
    {
            if(tmp->data < low->data)
            {
                    swap(pivot->link, tmp);
                    pivot = pivot->link;
            }
            tmp = tmp->link;
    }
    swap(low, pivot);
    qsort(low, pivot->plink);
    qsort(pivot->link, high);
}

int main()
{
    addLast(3);
    addLast(20);
    addLast(10);
    addLast(5);
    addLast(8);
    printf("Linked List before sorting \n");
    printList();

    qsort(first,last);

    printf("Linked List after sorting \n");
    printList();
}
