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
        printf("Genealogy has no data\n");
        return;
    }

    printf(" %s (%s  %s  %d  ): ", r->name, r->sex, r->dob, r->age);

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
    Node *p = findAge(root, name, age);

    if (p != NULL)
    {
        p->age = newAge;
    }
}

int markMem = 0, markChild = 0;

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

Node *memHavingMostChildren = NULL;
int maxChild = -1;
int findMemberHavingMostChildren(Node *r)
{
    int numChild = 0;
    Node *p = r->leftMostChild;
    if (p == NULL)
        return numChild;
    while (p != NULL)
    {
        int q = findMemberHavingMostChildren(p);
        if (q > maxChild)
        {
            maxChild = q;
            //memHavingMostChilden = p;
        }
        p = p->rightSibling;
        numChild++;
    }
    return maxChild;
}
int minAge = 0;
Node *minAgeMem = NULL;
void *findSmallestMember(Node *r)
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

void writeToFile(Node *r, char *fo)
{
    if (r == NULL)
    {
        printf("Genealogy has no data\n");
        return;
    }
    fprintf(fo," %s (%s  %s  %d  ): ", r->name, r->sex, r->dob, r->age);
    for (Node *p = r->leftMostChild; p != NULL; p = p->rightSibling)
    {
        fprintf(fo,"  %s ", p->name);
    }
    printf("\n");
    for (Node *p = r->leftMostChild; p != NULL; p = p->rightSibling)
    {
        writeToFile(p,fo);
    }
}
void saveToFile(char *filename)
{
    printf("Save data from file \"%s\" .......\n", filename);
    FILE *fo = fopen(filename, "w");
    writeToFile(root,fo);
    printf("End save data to file \"%s\" \n", filename);
    fclose(fo);
}

void menu()
{
    printf("-----------------------------\n");
    printf("\t\t load: load the genealogy from a text file\n");
    printf("\t\t add: add a member into the genealogy\n");
    printf("\t\t most-child: find member having the most children\n");
    printf("\t\t smallest: find smallest member\n");
    printf("\t\t find-member: find a member\n");
    printf("\t\t find-children: find a children\n");
    printf("\t\t update: update new age for a member\n");
    printf("\t\t save: save the genealogy into a file\n");
    printf("\t\t display: display the information of the genealogy\n");
    printf("\t\t exit: exit the program\n");
    printf("-----------------------------\n");
    printf("command: ");
}

void clear_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
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
            // char filename[256];
            // printf("Enter filename : ");
            // scanf("%s", filename);
            // loadFromFile("filename");
            loadFromFile("DATA");
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
            findSmallestMember(root);
            printf("Smallest member is %s (%s  %s  %d  )\n", minAgeMem->name, minAgeMem->sex, minAgeMem->dob, minAgeMem->age);
        }
    }
    return 0;
}
