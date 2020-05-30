#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_T 100
#define MAX_SZ 10000
#define MAX_L_WORD 100
typedef struct Node
{
    char *username;
    char *pass;
    struct Node *left;
    struct Node *right;
}Node;
Node *bst[MAX_T];
char fileName[50];
Node *makeNode(char *usr, char *pass)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p -> username = (char*)malloc(strlen(usr) + 1);
    sprintf(p -> username, "%s", usr);
    p -> pass = (char*)malloc(strlen(pass) + 1);
    sprintf(p -> pass, "%s", pass);
    p -> left = NULL;
    p -> right = NULL;
    return p;
}

Node *findNode(Node *r, char *usr)
{
    if (r == NULL) return NULL;
    int c = strcmp(usr, r -> username);
    if (c == 0) return r;
    if (c < 0) return findNode(r -> left, usr);
    return findNode(r -> right, usr);
}

Node *insertNode(Node *r, char *usr, char *pass)
{
    if (r == NULL) return makeNode(usr, pass);
    int c = strcmp(usr, r -> username);
    if (c < 0) r -> left = insertNode(r -> left, usr, pass);
    else if (c > 0) r -> right = insertNode(r -> right, usr, pass);
    return r;
}

void freeBST(Node *r)
{
    if (r == NULL) return ;
    freeBST(r -> left);
    freeBST(r -> right);
    free(r -> username);
    free(r -> pass);
    free(r);
    r = NULL;
}

void initDict()
{
    for (int h = 0; h < MAX_T; h++)
    {
        bst[h] = NULL;
    }
}

void freeDict()
{
    for (int h = 0; h < MAX_T; h++)
    {
        freeBST(bst[h]);
    }
}

int hashCode(char *s)
{
    int h = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        h = ((h * 256) % MAX_T + s[i]) % MAX_T;
    }
    if (h < 0) h = -h;
    return h;
}

int checkValidUsr(char *usr)
{
    return (strstr(usr, " ") == NULL);
}

int checkValidPass(char *pass)
{
    int ln = strlen(pass);
    if (ln < 6) return 0;
    for (int i = 0; i < ln; i++)
    {
        if (!((pass[i] >= 'a' && pass[i] <= 'z') || (pass[i] >= 'A' && pass[i] <= 'Z')
              || (pass[i] >= '0' && pass[i] <= '9') || pass[i] == '_' || pass[i] == '$')) return 0;
    }
    return 1;
}

void readFile(char *fileName)
{
    FILE *f = fopen(fileName, "r");
    char s[MAX_SZ];
    while (!feof(f))
    {
        char usr[MAX_L_WORD];
        fscanf(f, "%s", usr);
        if (strcmp(usr, "#") == 0) break;
        char pass[MAX_L_WORD];
        fscanf(f, "%s", pass);
        int h = hashCode(usr);
        bst[h] = insertNode(bst[h], usr, pass);
    }
    fclose(f);
}

void writeBST(Node* r, FILE *f)
{
    if (r == NULL) return ;
    writeBST(r -> left, f);
    if (strcmp(r -> username, "admin") != 0) fprintf(f, "%s %s\n", r -> username, r -> pass);
    writeBST(r -> right, f);
}

void writeFile(char *fileName)
{
    FILE *f = fopen(fileName, "w");
    for (int h = 0; h < MAX_T; h++)
    {
        writeBST(bst[h], f);
    }
    fprintf(f, "%s", "#");
    fclose(f);
}

Node* checkLogin(char *usr, char *pass)
{
    int h = hashCode(usr);
    Node *p = findNode(bst[h], usr);
    if (p != NULL)
    {
        if (strcmp(p -> pass, pass) == 0) return p;
    }
    return NULL;
}

void changePass(Node *r, char *newPass)
{
    if (r == NULL) return ;
    sprintf(r -> pass, "%s", newPass);
}

void printBST(Node *r)
{
    if (r == NULL) return ;
    printBST(r -> left);
    printf("%s\n", r -> username);
    printBST(r -> right);
}

void viewListUser()
{
    printf("User list:\n");
    printf("-----------------------\n");
    for (int h = 0; h < MAX_T; h++)
    {
        printBST(bst[h]);
    }
    printf("-----------------------\n");
}

void viewOper(int choice)
{
    if (choice == 1 || choice == 2 || choice == 3)
    {
        // check usr and pass
        printf("\nInsert the username: ");
        char usr[MAX_L_WORD];
        gets(usr);
        if (checkValidUsr(usr) == 0)
        {
            viewOper(++choice);
            return ;
        }
        printf("\nInsert the pass: ");
        char pass[MAX_L_WORD];
        gets(pass);
        if (checkValidPass(pass) == 0)
        {
            printf("\nYour password is invalid\n");
            viewOper(++choice);
            return ;
        }
        Node *p = checkLogin(usr, pass);
        if (p == NULL)
        {
            printf("\nYour username does not exist or your password does not match\n");
            viewOper(++choice);
            return ;
        }
        // if normal usr
        if (strcmp(p -> username, "admin") != 0)
        {
            printf("\nHello user %s", "something");
            printf("\nDo you want to change your password(Y/N): ");
            fflush(stdin);
            char c;
            c = getchar();
            if (c != 'Y' && c != 'y')
            {
                printf("\nOkay. Goodbye for now\n");
                return ;
            }
            printf("\nInsert your new password:\n");
            char newPass[MAX_L_WORD];
            do
            {
                fflush(stdin);
                gets(newPass);
                if (checkValidPass(newPass) == 0) printf("Your new password is not valid. Enter again:\n");
            } while (checkValidPass(newPass) == 0);
            changePass(p, newPass);
        }
        // if admin
        else
        {
            printf("\nWelcome back admin");
            viewOper(0);
        }
    }
    if (choice == 0)
    {
        printf("\n==============Menu==============\n");
        printf("1. Insert a new user\n");
        printf("2. Change a user password\n");
        printf("3. View Users list\n");
        printf("4. Exit\n");
        printf("\n================================\n");
        fflush(stdin);
        char opt[100];
        while (1)
        {
            printf("\n================================\n");
            printf("Insert your option, dear admin\n");
            gets(opt);
            if (strlen(opt) != 1) printf("\nInvalid option\n");
            else
            {
                int h;
                switch(opt[0])
                {
                case '1':
                    {
                    printf("Insert the new username: \n");
                    char newUsr[MAX_L_WORD];
                    do
                    {
                        gets(newUsr);
                        if (checkValidUsr(newUsr) == 0) printf("Username is not valid. Enter again:\n");
                        else
                        {
                            h = hashCode(newUsr);
                            if (findNode(bst[h], newUsr) != NULL) printf("Username did exist. Enter again:\n");
                        }
                    } while (checkValidUsr(newUsr) == 0 || findNode(bst[h], newUsr) != NULL);
                    printf("Insert the new password: \n");
                    char newPass[MAX_L_WORD];
                    do
                    {
                        gets(newPass);
                        if (checkValidPass(newPass) == 0) printf("Password is not valid. Enter again:\n");
                    } while (checkValidPass(newPass) == 0);
                    bst[h] = insertNode(bst[h], newUsr, newPass);
                    }
                    printf("\nCreating new user completetly\n");
                    break;
                case '2':
                    {
                    printf("Enter the username you want to repassword:\n");
                    char usr[MAX_L_WORD];
                    Node *p = (Node*)malloc(sizeof(Node));
                    do
                    {
                        gets(usr);
                        if (checkValidUsr(usr) == 0) printf("Username is not valid. Enter again:\n");
                        else
                        {
                            h = hashCode(usr);
                            p = findNode(bst[h], usr);
                            if (p == NULL) printf("Username does not exist. Enter again:\n");
                        }
                    } while (checkValidUsr(usr) == 0 || p == NULL);
                    printf("Insert the new password: \n");
                    char newPass[MAX_L_WORD];
                    do
                    {
                        gets(newPass);
                        if (checkValidPass(newPass) == 0) printf("Password is not valid. Enter again:\n");
                    } while (checkValidPass(newPass) == 0);
                    changePass(p, newPass);
                    }
                    printf("\nChanging pass completetly\n");
                    break;
                case '3':
                    viewListUser();
                    break;
                case '4':
                    printf("\nProgram is shutting down ---\n");
                    return ;
                default:
                    printf("\nInvalid option, dear admin\n");
                    break;
                }
            }
        }
        return ;
    }
    return ;
}

int main()
{
    sprintf(fileName, "%s", "pass.txt");
    int h = hashCode("admin");
    initDict();
    bst[h] = insertNode(bst[h], "admin", "luvH1010");
    readFile(fileName);
    viewOper(1);
    writeFile(fileName);
    freeDict();
    return 0;
}
