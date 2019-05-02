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
void clear_buffer()
{
    while (getchar() != '\n')
        ;
}
void printNode(Node *p) {
    printf("!%s! !%s! !%s! !%d! \n", p->name, p->dob, p->sex, p->age);
}
void loadFromFile(char *filename)
{

    printf("Load data from file \"%s\" .......\n", filename);
    FILE *f = fopen(filename, "r");
    int old;
    char name[50];
    char sex[10];
    char dob[11];
    fscanf(f, "%[^\n]\n", name);
    fscanf(f, "%s %s %d", sex, dob, &old);
    printf("sex %s name %s dob %s old %d\n", sex, name, dob, old);
    root = makeNode(name, sex, dob, old);
    printf("Loaded : \n");
    printNode(root);
    printf("End Load data from file \"%s\" .......\n", filename);
    fclose(f);
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
        ///else if(strcmp(cmd, "display") == 0)
        //printGenealogy(root);
    }
    return 0;
}
