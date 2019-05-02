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
        return ;
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
            fscanf(f, "%s %s %d\n", sex, dob, &old);
            root = makeNode(name, sex, dob, old);
        }
        else
        {
            char parentName[30];
            fscanf(f, "%s %s %d\n", sex, dob, &old);
            fscanf(f, "%[^\n]\n", parentName);
            addMem(name, sex, dob, old, parentName); 
        }
    }
    printGenealogy(root);
    printf("End Load data from file \"%s\" \n", filename);
    fclose(f);
}

void updateAge(char *name, int age, int newAge)
{
    // if (root == NULL)
    //     return NULL;
    // if (strcmp(r->name, parentName) == 0)
    //     return r;
    // Node *p = r->leftMostChild;
    // while (p != NULL)
    // {
    //     Node *q = find(p, parentName);
    //     if (q != NULL)
    //         return q;
    //     p = p->rightSibling;
    // }
    // return NULL;
}

void menu()
{
    printf("-----------------------------\n");
    printf("\t\t load: load the genealogy from a text file\n");
    printf("\t\t add: add a member into the genealogy\n");
    printf("\t\t find: find a member\n");
    printf("\t\t update: update new age for a member\n");
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
            loadFromFile(filename);
        }
        else if (strcmp(cmd, "display") == 0)
            printGenealogy(root);
    }
    //loadFromFile("DATA");
    return 0;
}
