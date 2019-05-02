#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char name[50];
    char sex[10];
    char dob[10];
    int age;
    struct Node *leftMostChild;
    struct Node *rightSibling;
} Node;

Node *root;



Node *makeNode(char *fullName, char *sexual, char *date, int old)
{
    Node *p = (Node *)malloc(sizeof(Node)); //allocate memory for p
    strcpy(fullName, p->name);
    strcpy(sexual, p->sex);
    strcpy(date, p->dob);
    p->age = old;
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    return p;
}

Node *find(Node *r, char *parentName)
{
    //return a pointer to a node with name is parentNam on the tree rooted at r
    if (r == NULL)
        return NULL;
    if (!strcmp(r->name, parentName))
        return r;
    Node *p = r->leftMostChild;
    while (p != NULL)
    {
        Node *q = find(p, parentName);
        if (q != NULL)
            return q;
        p = p->rightSibling;
    }
    return NULL;
}

void addMem(char *fullName, char *sexual, char *date, int old, char *parentName)
{
    //create a node having information, add this node at the appropriate position of the list of children of node parentName
    Node *p = find(root, parentName);
    if (p == NULL)
        return NULL;
    Node *q = makeNode(fullName, sexual, date, old);
    if (p->leftMostChild == NULL)
        p->leftMostChild = q;
    else
    {
        p = p->leftMostChild;
        while (p->rightSibling != NULL)
        {
            p = p->rightSibling;
        }
        p->rightSibling = q;
    }
}

void printGenealogy(Node *r)
{
    if (r == NULL)
    {
        printf("Tree has no data\n");
        return;
    }

    printf(" %s :", r->name);

    for (Node *p = r->leftMostChild; p != NULL; p = p->rightSibling)
    {
        printf("  %s ", p->name);
    }
    printf("\n");
    for (Node *p = r->leftMostChild; p != NULL; p = p->rightSibling)
    {
        printGenealogy(p);
    }
}

void updateAge(char *name, char *dob, int newAge)
{
}

Node *findMem(char *name, char *sex, int fromAge, int toAge)
{
}

Node *findChild(char *sex, char *parentName)
{
}

Node *findMemHavingMostChild()
{
}

Node *findSmallestMem()
{
}

void clear_buffer()
{
    while (getchar() != '\n')
        ;
}

void saveToFile(char *filename)
{
    printf("Save data from file \"%s\" .......\n", filename);
}

void loadFromFile(char *filename)
{
    printf("Load data from file \"%s\" .......\n", filename);
    FILE *f = fopen(filename, "r");
    fscanf(f,"%[\n]%*c ",root->name);
    fscanf(f,"%s %s %d ", root->sex, root->dob, root->age);
}

void menu()
{
    printf("-----------------------------\n");
    printf("\t\t load: load the genealogy from a text file\n");
    printf("\t\t add: add a member into the genealogy\n");
    printf("\t\t find: find a member\n");
    printf("\t\t save: save the genealogy into a file\n");
    printf("\t\t display: display the information of the genealogy\n");
    printf("\t\t exit: exit the program\n");
    printf("-----------------------------\n");
    printf("command: ");
}
int main()
{

    while (1)
    {
        char cmd[256];
        menu();
        scanf("%s", cmd);
        if (strcmp(cmd, "exit") == 0)
            break;
        else if (strcmp(cmd, "load") == 0)
        {
            char filename[256];
            printf("Enter filename : ");
            scanf("%s", filename);
            clear_buffer();
            loadFromFile(filename);
        }
        else if (strcmp(cmd, "save") == 0)
        {
            char filename[256];
            printf("Enter filename : ");
            scanf("%s", filename);
            clear_buffer();
            saveToFile(filename);
        }
        else if(strcmp(cmd, "find") == 0)
        {
            int fromAge, toAge;
            char *name, *sexual;
            printf("Enter name : ");
            gets(name);
            printf("Enter sexual : ");
            gets(sexual);
            printf("From age : ");
            scanf("%d", &fromAge);
            printf("To age : ");
            scanf("%d", &toAge);
            findMem(name, sexual, fromAge, toAge);
        }
        else if(strcmp(cmd, "add") == 0)
        {
            char name[30], sexual[10], date[10], parentName[30];
            int old;
            printf("Enter parent's name : ");
            gets(parentName);
            printf("Enter name : ");
            gets(name);
            printf("Enter sexual : ");
            gets(sexual);
            printf("Enter date of birth : ");
            gets(date);
            printf("Enter age : ");
            scanf("%d", &old);
            addMem(name, sexual, date, old, parentName);
        }
        else if(strcmp(cmd, "display") == 0)
            printGenealogy(root);
    }

    return 0;
}
