#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int k , x;
int a1[100], a2[100];

typedef struct Node{
	int co;
	int po;
	struct Node* next;
}Node;

Node* first, *last;

Node* makeNode(int a1, int a2)
{
	Node* p = (Node*) malloc( sizeof(Node)); 
	p->co = a1;
	p->po = a2;
	p->next = NULL;
	return p;
}

void addLast( int a1, int a2)
{
	Node* p = makeNode(a1,a2);
	if(last!=NULL)
		last->next=p;
	last = p;
	if(first==NULL)
		first=p;
}

void addData()
{
	for(int i=0;i<=k; i++)
	{
		addLast(a1[i],a2[i]);
	}
}

void printList()
{
	for(Node* p  =first; p != NULL; p=p->next)
		{
			printf("%d ",p->co);
			printf("%d ",p->po);
		}
	printf("\n");
}

int polynomial(int k, int x)
{
	int ans=0;
	Node* p = first;
	for(Node* p  =first; p != NULL; p=p->next) 
		{
			ans += p->co * pow(x, (p->po));
			
		}
	return ans;
}

int main()
{
	FILE* f = fopen("polynomialInput.txt","r");

	fscanf(f,"%d %d", &k,&x);
	for(int i = 0 ; i <=k ; i++ )
		fscanf(f,"%d",&a1[i]);
	for(int i = 0 ; i <=k ; i++ )
		fscanf(f,"%d",&a2[i]);
	addData();
	int ans = polynomial(k, x);
	printf("Result : %d\n", ans);
	fclose(f);
	return 0;
}