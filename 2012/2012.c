#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

typedef struct Node
{
    char name[30];
    float grade;
    char group[30];
    struct Node *next;
}Node;

Node* firstExcellent;
Node* lastExcellent;
Node* firstE;
Node* lastE;
Node* firstD;
Node* lastD;

Node* makeNode(char* name, float grade, char* group)
{
	Node* p = (Node*) malloc( sizeof(Node));  //allocate memory for p 
    strcpy(p->name, name);
	p->grade = grade;
	p->next = NULL;
	return p;
}

void addLast(char* name, float grade, char* group, Node* first, Node* last)
{
	Node* p = makeNode(name, grade, group);
	if(last!=NULL)
		last->next=p;
	last = p;
	if(first==NULL)
		first=p;
}


// void normalize(char *t)
// {
//     if (t[strlen(t) - 1] == 10 || t[strlen(t) - 1] =='\n')
//         t[strlen(t) - 1] == '\0';
// }

// void printList(char *filename, Node* first, Node* last)
// {
//     FILE* f = fopen(filename, "w");
// 	for(Node* p  =first; p != NULL; p=p->next)
// 		fprintf(f,"%s : %.1f : %s \n",p->name,p->grade, p->group);
// 	fprintf(f,"\n");
//     fclose(f);
// }

void printList(Node* first, Node* last)
{
	for(Node* p  =first; p != NULL; p=p->next)
		printf("%s : %.1f : %s \n",p->name,p->grade, p->group);
	printf("\n");
    
}

void search(float x)
{
    int have = 0;
    for(Node* p  =firstD; p != NULL; p=p->next)
    {
        if(p->grade >= x)
		{
            printf("%s : %.1f\n",p->name,p->grade);
            have = 1;
        }
    }

    for(Node* p  =firstE ; p != NULL; p=p->next)
    {
        if(p->grade >= x)
		{
            printf("%s : %.1f\n",p->name,p->grade);
            have = 1;
        }
    }

    if( have ==0)
     printf("Khong co ai diem >= %.1f\n",x);
}


void searchExcellent()
{
    int haveE = 0;
    for(Node* p  =firstD; p != NULL; p=p->next)
    {
        if(p->grade >= 8.5)
		{
            addLast(p->name,p->grade, p->group, firstExcellent, lastExcellent);
            //fprintf("%s : %.1f: %s \n",p->name,p->grade, p->group);
            haveE = 1;
        }
    }

    for(Node* p  =firstE; p != NULL; p=p->next)
    {
        if(p->grade >= 8.5)
		{
            addLast(p->name,p->grade, p->group, firstExcellent, lastExcellent);
            haveE = 1;
        }
    }

    if( haveE ==0)
     printf("Khong co ai xuat sac\n");
    printList(firstExcellent, lastExcellent);
}


int contain(char *s, char c)
{
    for (int i = 0; i < strlen(s); i++)
        if (s[i] == c)
            return 1;
    return 0;
}
void readFromFile(char* filename, Node* first, Node* last, char* group)
{
    printf("Read\n");
    FILE* f = fopen(filename, "r");  
    while(1)
    {
        char name[30];
        float grade;
        // fgets(name, sizeof name, f);
        // normalize(name);
        if (contain(name, '#'))
            break;
        fscanf(f,"%[^\n]",name);
        fscanf(f,"\n%f",&grade);
        addLast(name,grade,group,first, last);
        
    }
    //printList("out2012", first, last);
    printList(first, last);
    fclose(f);
}
void MENU()
{
  printf("============\nMENU\n");

  printf("1. Read file\n");

  printf("2. Search\n");

  printf("3. Excellent list\n");

  printf("4. Write file\n");

  printf("5. Combine lists\n");

  printf("6. Quit\n");
}
void clear_buffer()
{
  while(getchar()!='\n');
}

int main()
{
  int choice;
  char input[50];
  int while_condition = 1;
  do
    {
      MENU();
      printf("Your choice is :");
      scanf("%s", input);
      clear_buffer();
      choice = atoi(input);

      switch (choice)
        {
        case 1:
        printf("Read data of class :");
        char class[5];
        gets(class);
        
        if(strcmp(class,"6d")==0)
            readFromFile(class, firstD, lastD, "6d");
         if(strcmp(class,"6e")==0)
            readFromFile(class, firstE, lastE, "6e");   
	  
	  break;

        case 2:
        printf("Nhap diem : ");
        float x;
        scanf("%f", &x);
            search(x);
	  
	  break;

        case 3:
            searchExcellent();
	  
	  break;

        case 4:

	  
	  break;

        case 5:

	  
	  break;

        case 6:
	  while_condition = 0;
	  break;

        default:
	  printf("Wrong choice !!\n Please choose again !!\n");
	  break;
        }

    } while (while_condition);
  return 0;
}


