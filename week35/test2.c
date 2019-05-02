#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char name[50];
    char sex[10];
    char dob[11];
    int age;
    struct Node *leftMostChild;
    struct Node *rightSibling;
} Node;

Node *root;

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

Node *makeNode(char *fullName, char *sexual, char *date, int old)
{
    Node *p = (Node *)malloc(sizeof(Node)); //allocate memory for p
    strcpy(p->name, fullName);
    strcpy(p->sex, sexual);
    strcpy(p->dob, date);
    p->age = old;
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    return p;
}

Node *find(Node *r, char *parentName)
{
    //return a pointer to a node with name is parentName on the tree rooted at r
    if (r == NULL)
        return NULL;
    if (strcmp(r->name, parentName) == 0)
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

void loadFromFile(char *filename)
{

    printf("Load data from file \"%s\" .......\n", filename);
    FILE *f = fopen(filename, "r");
    root = NULL;
    int cnt = 0;
    while (1)
    {
        int old;
        char name[50];
        char sex[10];
        char dob[11];
        fscanf(f, "%[^\n]\n", name);
        if (strcmp(name, "stop") == 0)
            break;
        if (root == NULL)
        {
            fscanf(f, "%s %s %d", sex, dob, &old);
            root = makeNode(name, sex, dob, old);
            //printf("Sex %s\tDOB %s\tAge %d\t\n", sex, dob, old);
        }
        else
        {
            char parentName[30];
            fscanf(f, "%s %s %d\n", sex, dob, &old);
            
            fscanf(f,"%[^\n]\n",parentName);
            printf("Sex %s\tDOB %s\tAge %d\tParent name %s \n", sex, dob, old, parentName);
            
            addMem(name, sex, dob, old, parentName);
            
        }
    }
    //printGenealogy(root);
    printf("End Load data from file \"%s\" \n", filename);
    fclose(f);
}

int main()
{
    // while (1)
    // {
    //     char cmd[256];
    //     menu();
    //     scanf("%s", cmd);
    //     if (strcmp(cmd, "exit") == 0)
    //         break;
    //     else if (strcmp(cmd, "load") == 0)
    //     {
    //         char filename[256];
    //         printf("Enter filename : ");
    //         scanf("%s", filename);
    //         loadFromFile(filename);
    //     }
    //     else if (strcmp(cmd, "display") == 0)
    //         printGenealogy(root);
    // }
    loadFromFile("DATA.txt");
    return 0;
}
