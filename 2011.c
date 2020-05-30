#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_L_WORD 21
#define MAX_SZ 100
typedef struct Node
{
    char *word;
    char *def;
    struct Node *left;
    struct Node *right;
}Node;

Node *root = NULL;

Node* makeNode(char *word, char *def)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p -> word = (char*)malloc(strlen(word) + 1);
    sprintf(p -> word, "%s", word);
    p -> def = (char*)malloc(strlen(def) + 1);
    sprintf(p -> def, "%s", def);
    p -> left = NULL;
    p -> right = NULL;
    return p;
}

Node *find(Node *r, char *k)
{
    if (r == NULL) return NULL;
    int c = strcmp(k, r -> word);
    if (c == 0) return r;
    if (c < 0) return find(r -> left, k);
    return find(r -> right, k);
}

Node *insert(Node *r, char *word, char *def)
{
    if (r == NULL) return makeNode(word, def);
    int c = strcmp(word, r -> word);
    if (c < 0) r -> left = insert(r -> left, word, def);
    else if (c > 0) r -> right = insert(r -> right, word, def);
    return r;
}

void freeBST(Node *r)
{
    if (r == NULL) return;
    freeBST(r -> left);
    freeBST(r -> right);
    free(r -> word);
    free(r -> def);
    free(r);
    r = NULL;
}

void normalize(char *s)
{
    if (s[strlen(s) - 1] == 10) s[strlen(s) - 1] = '\0';
}

int ignoreChar(char c)
{
    if (c == ' ' || c == '\t' || c == ',' || c == '.') return 1;
    return 0;
}

void viewDict(Node* r)
{
    if (r == NULL) return ;
    viewDict(r -> left);
    printf("%-20s%s\n", r -> word, r -> def);
    viewDict(r -> right);
}

void readFile(char *fileName)
{
    FILE *f = fopen(fileName, "r");
    while(!feof(f))
    {
        char word[21];
        char def[21];
        fscanf(f, "%s", word);
        fgetc(f);
        fgets(def, 21, f);
        normalize(word);
        normalize(def);
        root = insert(root, word, def);
    }
    fclose(f);
}

int concenStr(char *des, char *source, int startP)
{
    int ln = strlen(source);
    if (startP != 0)
    {
        des[startP] = ' ';
        startP++;
    }
    int i;
    for (i = startP; i < startP + ln; i++)
    {
        des[i] = source[i - startP];
    }
    return i;
}

void transEV()
{
    char s[MAX_SZ];
    char trans[MAX_SZ];
    printf("Enter a sentence to translate:\n");
    fflush(stdin);
    gets(s);
    normalize(s);
    char str[MAX_L_WORD];
    int i = 0, k = 0;
    while(i < strlen(s))
    {
        while(i < strlen(s) && (ignoreChar(s[i]))) i++;
        if (i >= strlen(s)) break;
        int j = 0;
        while (i < strlen(s) && !ignoreChar(s[i]))
        {
            str[j] = tolower(s[i]);
            j++;
            i++;
        }
        str[j] = '\0';
        Node *p = find(root, str);
        if (p != NULL)
        {
//            printf("%s ",p -> def);
            k = concenStr(trans, p -> def, k);
        }
        else
        {
            printf("Missing meaning for \"%s\". Enter the new meaning:\n", str);
            fflush(stdin);
            char def[MAX_L_WORD];
            gets(def);
            normalize(def);
            k = concenStr(trans, def, k);
            root = insert(root, str, def);
        }
    }
    trans[k] = '\0';
    printf("\nTranslation is: %s\n", trans);
}

void writeFile(Node *r, FILE *f)
{
    if (r == NULL) return ;
    writeFile(r -> left, f);
    fprintf(f, "%s %s\n", r -> word, r -> def);
    writeFile(r -> right, f);
}

void menu()
{
    printf("\n==============Menu==============\n");
    printf("1. Doc file\n");
    printf("2. Hien thi\n");
    printf("3. Dich Anh Viet\n");
    printf("4. Exit\n");
    printf("\n================================\n");
}

int main()
{
    char opt[100];
    while (1)
    {
        menu();
        printf("Insert your option, dear admin\n");
        fflush(stdin);
        gets(opt);
        if (strlen(opt) != 1) printf("\nInvalid option\n");
        else
        {
            switch(opt[0])
            {
            case '1':
                {
                    readFile("data.txt");
                }
                printf("\nEntering data completely\n");
                break;
            case '2':
                {
                    viewDict(root);
                }
                printf("\Viewing Dict completely\n");
                break;
            case '3':
                {
                    transEV();
                }
                printf("\nTranslating completely\n");
                break;
            case '4':
                printf("\nSaving program===pleasewait");
                {
                    FILE *f = fopen("data.txt", "w");
                    writeFile(root, f);
                    fclose(f);
                    freeBST(root);
                }
                printf("\nProgram is shutting down---\n");
                exit(0);
            default:
                printf("\nInvalid option, dear admin\n");
                break;
            }
        }
    }
}
