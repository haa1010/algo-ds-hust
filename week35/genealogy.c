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

int markMem = 0, markChild = 0, maxChild = 0, minAge = 1000;
Node *memHavingMostChildren, *minAgeMem;

void clear_buffer();
void menu();
void printGenealogy(Node *r);
Node *makeNode(char *fullName, char *sexual, char *date, int old);
Node *find(Node *r, char *parentName);
Node *findAge(Node *r, char *name, int age);
void addMem(char *fullName, char *sexual, char *date, int old, char *parentName);
void loadFromFile(char *filename);
void updateAge(char *name, int age, int newAge);
void findMember(Node *r, char *name, char *sex, int fromAge, int toAge);
void findChildren(Node *r, char *sex, char *parentName);
void findMemberHavingMostChildren(Node *r);
void findSmallestMember(Node *r);
void display(Node *r, FILE *f);
void saveToFile(char *filename);


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
            loadFromFile("filename");
        }
        else if (strcmp(cmd, "display") == 0)
            printGenealogy(root);
        else if (strcmp(cmd, "update") == 0)
        {
            printf("Enter name : ");
            char name[30];
            clear_buffer();
            gets(name);
            printf("Enter age and new age : ");
            int age, newAge;
            scanf("%d %d", &age, &newAge);
            updateAge(name, age, newAge);
            printGenealogy(root);
        }
        else if (strcmp(cmd, "find-member") == 0)
        {
            char name[30], sex[10];
            printf("Enter name : ");
            clear_buffer();
            gets(name);
            printf("Enter sex : ");
            gets(sex);
            printf("Enter from age and to age : ");
            int fromAge, toAge;
            scanf("%d %d", &fromAge, &toAge);
            findMember(root, name, sex, fromAge, toAge);
            if (markMem == 0)
                printf("Don't have any member sastified conditions.\n");
        }
        else if (strcmp(cmd, "find-children") == 0)
        {
            clear_buffer();
            char parentName[30], sex[10];
            printf("Enter parent's name : ");
            gets(parentName);
            printf("Enter sex : ");
            gets(sex);
            findChildren(root, sex, parentName);
            if (markChild == 0)
                printf("Don't have any member sastified conditions.\n");
        }
        else if (strcmp(cmd, "smallest") == 0)
        {
            printf("ok\n");
            findSmallestMember(root);
            printf("Smallest member is %s (%s  %s  %d  )\n", minAgeMem->name, minAgeMem->sex, minAgeMem->dob, minAgeMem->age);
        }
        else if (strcmp(cmd, "most-child") == 0)
        {
            findMemberHavingMostChildren(root);
            printf("Member has most children is %s (%s  %s  %d ) : %d children\n", memHavingMostChildren->name, memHavingMostChildren->sex, memHavingMostChildren->dob, memHavingMostChildren->age, maxChild);
        }
        else if (strcmp(cmd, "add") == 0)
        {
            char name[50], parentName[20], sex[10], dob[11];
            int age;
            clear_buffer();
            printf("Enter name : ");
            gets(name);
            printf("Enter sex : ");
            gets(sex);
            printf("Enter date of birth : ");
            gets(dob);
            printf("Enter parent name : ");
            gets(parentName);
            printf("Enter age : ");
            scanf("%d", &age);
            addMem(name, sex, dob, age, parentName);
        }
        else if (strcmp(cmd, "save") == 0)
        {
            saveToFile("save");
        }
    }
    return 0;
}

void menu()
{
    printf("-----------------------------\n");
    printf("\t\t add:           add a member into the genealogy\n");
    printf("\t\t display:       display the information of the genealogy\n");
    printf("\t\t find-member:   find a member\n");
    printf("\t\t find-children: find a children\n");
    printf("\t\t load:          load the genealogy from a text file\n");
    printf("\t\t most-child:    find member having the most children\n");
    printf("\t\t smallest:      find smallest member\n");
    printf("\t\t save:          save the genealogy into a file\n");
    printf("\t\t update:        update new age for a member\n");
    printf("\t\t exit:          exit the program\n");
    printf("-----------------------------\n");
    printf("command: ");
}

void clear_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void printGenealogy(Node *r)
{
    if (r == NULL)
    {
        printf("Genealogy has no data\n");
        return;
    }

    printf("     %s (%s  %s  %d  ): ", r->name, r->sex, r->dob, r->age);

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

//MAKE NODE

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

//FIND A NODE BY NAME
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

//FIND NODE BY NAME AND AGE

Node *findAge(Node *r, char *name, int age)
{
    if (r == NULL)
        return NULL;
    if ((strcmp(r->name, name) == 0) && (r->age == age))
        return r;
    Node *p = r->leftMostChild;
    while (p != NULL)
    {
        Node *q = findAge(p, name, age);
        if (q != NULL)
            return q;
        p = p->rightSibling;
    }
    return NULL;
}

//ADD A MEMBER TO GENEALOGY

void addMem(char *fullName, char *sexual, char *date, int old, char *parentName)
{
    //create a node having information, add this node at the appropriate position of the list of children of node parentName
    Node *p = find(root, parentName);
    if (p == NULL)
        return;
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

//LOAD FROM FILE

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
    printf("End Load data from file \"%s\" .\n", filename);
    fclose(f);
}

//UPDATE NEW AGE FOR A MEMBER
void updateAge(char *name, int age, int newAge)
{
    Node *p = findAge(root, name, age);

    if (p != NULL)
    {
        p->age = newAge;
    }
}

//FIND A MEMBER BY NAME SEX AGE

void findMember(Node *r, char *name, char *sex, int fromAge, int toAge)
{
    if (r == NULL)
        return;
    int tmp = r->age;
    if ((strcmp(r->name, name) == 0) && (strcmp(r->sex, sex) == 0) && (tmp > fromAge) && (tmp < toAge))
    {
        markMem = 1;
        printf("--- Find member result : %s (%s  %s  %d  )\n", r->name, r->sex, r->dob, r->age);
    }
    Node *p = r->leftMostChild;
    while (p != NULL)
    {
        findMember(p, name, sex, fromAge, toAge);
        p = p->rightSibling;
    }
    return;
}

//FIND CHILDREN BY PARENT NAME AND SEX
void findChildren(Node *r, char *sex, char *parentName)
{
    if (r == NULL)
        return;
    if (strcmp(r->name, parentName) == 0)
    {
        for (Node *p = r->leftMostChild; p != NULL; p = p->rightSibling)
            if (strcmp(p->sex, sex) == 0)
            {
                markChild = 1;
                printf("--- Find children result : %s (%s  %s  %d  )\n", p->name, p->sex, p->dob, p->age);
            }
    }
    Node *p = r->leftMostChild;
    while (p != NULL)
    {
        findChildren(p, sex, parentName);
        p = p->rightSibling;
    }
    return;
}

//FIND MEMBER HAS THE MOST CHILDREN

void findMemberHavingMostChildren(Node *r)
{
    int numChild = 0;
    if (r == NULL)
    {
        return NULL;
    }
    Node *p;
    for (p = r->leftMostChild; p != NULL; p = p->rightSibling)
    {
        numChild++;
    }
    if (numChild > maxChild)
    {
        maxChild = numChild;
        memHavingMostChildren = r;
    }
    for (Node *p = r->leftMostChild; p != NULL; p = p->rightSibling)
    {
        findMemberHavingMostChildren(p);
    }
}

//FIND MEMBER HAS THE SMALLEST AGE

void findSmallestMember(Node *r)
{
    if (r == NULL)
        return;
    if (r->age < minAge)
    {
        minAge = r->age;
        minAgeMem = r;
    }
    Node *p = r->leftMostChild;
    while (p != NULL)
    {
        findSmallestMember(p);
        p = p->rightSibling;
    }
}
void display(Node *r, FILE *f)
{
    if (r == NULL)
        return;
    Node *p;
    for (p = r->leftMostChild; p != NULL; p = p->rightSibling)
    {
        fprintf(f, "%s %s %s %d %s\n", p->name, p->sex, p->dob, p->age, r->name);
    }
    for (p = r->leftMostChild; p != NULL; p = p->rightSibling)
        display(p, f);
}
void saveToFile(char *filename)
{
    printf("saving data to file %s .......\n", filename);
    FILE *f = fopen(filename, "w");
    fprintf(f, "%s %s %s %d\n", root->name, root->sex, root->dob, root->age);
    display(root, f);
    fprintf(f, "-1");
    fclose(f);
}