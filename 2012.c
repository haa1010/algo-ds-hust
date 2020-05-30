#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Cbasic
{
    char *name;
    float score;
    struct Cbasic *next;
}Cbasic;

typedef struct NodeType
{
    Cbasic *head;
    Cbasic *tail;
} NodeType;

Cbasic *first6D = NULL, *last6D = NULL;
Cbasic *first6E = NULL, *last6E = NULL;
Cbasic *firstEx = NULL, *lastEx = NULL;
Cbasic Data[100], Data1[100], Data2[100];

int cntBiggerX = 0;

void normalize(char *s)
{
    if (s[strlen(s) - 1] == 10) s[strlen(s) - 1] = '\0';
}

Cbasic *makeNode(char *name, float score)
{
    Cbasic *p = (Cbasic*)malloc(sizeof(Cbasic));
    p -> score = score;
    p -> name = (char*)malloc(strlen(name) + 1);
    sprintf(p -> name, "%s", name);
    p -> next = NULL;
    return p;
}

NodeType addLastLL(Cbasic *startP, Cbasic *endP, char *name, float score)
{
    Cbasic *p = makeNode(name, score);
    if (endP != NULL)
    {
        endP -> next = p;
    }
    endP = p;
    if (startP == NULL)
        startP = p;
    NodeType pL;
    pL.head = startP;
    pL.tail = endP;
    return pL;
}

NodeType readFileLL(char *fileName, Cbasic *startP, Cbasic *endP)
{
    FILE *f = fopen(fileName, "r");
    NodeType p;
    int cntLine = 1;
    char inS[100];
    char name[100];
    float score;
    while (!feof(f))
    {
        fgets(inS, 100, f);
        if (cntLine % 2 != 0)
        {
            normalize(inS);
            strcpy(name, inS);
        }
        else
        {
            score = atof(inS);
            p = addLastLL(startP, endP, name, score);
            startP = p.head;
            endP = p.tail;
        }
        cntLine++;
    }
    if (cntLine % 2 == 0)
    {
        printf("\nThe last student(%s) score field is missing. Enter the score: \n", name);
        scanf("%f", &score);
        p = addLastLL(startP, endP, name, score);
        startP = p.head;
        endP = p.tail;
    }
    fclose(f);
    return p;
}

void viewLL(Cbasic *startP)
{
    printf("Ten                 Diem\n");
    for (Cbasic *p = startP; p != NULL; p = p -> next)
    {
        printf("%-20s%.1f\n", p -> name, p -> score);
    }
}

void viewLL2(Cbasic *startP)
{
    printf("Ten                 Diem      Dia chi bo nho\n");
    for (Cbasic *p = startP; p != NULL; p = p -> next)
    {
        printf("%-20s%2.1f%-7s%p\n", p -> name, p -> score, "",p);
    }
}

void searchBiggerX(Cbasic *startP, int x)
{
    for (Cbasic *p = startP; p != NULL; p = p -> next)
    {
        if (p -> score >= x)
        {
            cntBiggerX++;
            if (cntBiggerX == 1)
            {
                printf("Students that have higher score than %d is: \n", x);
                printf("Ten                 Diem\n");
            }
            printf("%-20s%.1f\n", p -> name, p -> score);
        }
    }
}

void writeFile(char *fileName, Cbasic *startP)
{
    FILE *f = fopen(fileName, "w");
    while (startP != NULL)
    {
        fprintf(f, "%s\n", startP -> name);
        if (startP -> next != NULL)
        {
            fprintf(f, "%f\n", startP -> score);
        }
        else
        {
            fprintf(f, "%f", startP -> score);
            break;
        }
        startP = startP -> next;
    }
    fclose(f);
}

void exLL(Cbasic *startP, Cbasic *endP, float x)
{
    NodeType p;
    for (; startP != NULL; startP = startP -> next)
    {
        if (startP -> score >= x)
        {
            p = addLastLL(firstEx, lastEx, startP -> name, startP -> score);
            firstEx = p.head;
            lastEx = p.tail;
        }
    }
}

void copyNode(Cbasic *a, Cbasic *b)
{
    a -> name = (char*)malloc(sizeof(char) * 100);
    strcpy(a -> name, b -> name);
    a -> score = b -> score;
}

int enterData(Cbasic Data[], Cbasic *startP)
{
    int i = 0;
    while (startP != NULL)
    {
        copyNode(&Data[i], startP);
        startP = startP -> next;
        i++;
    }
    return i;
}

void merge(Cbasic Data[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    Cbasic L[n1], R[n2];
    for (i = 0; i < n1; i++)
        copyNode(&L[i], &Data[l + i]);
    for (j = 0; j < n2; j++)
        copyNode(&R[j], &Data[m + 1 + j]);
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i].score <= R[j].score)
        {
            copyNode(&Data[k], &L[i]);
            i++;
        }
        else
        {
            copyNode(&Data[k], &R[j]);
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        copyNode(&Data[k], &L[i]);
        i++;
        k++;
    }
    while (j < n2)
    {
        copyNode(&Data[k], &R[j]);
        j++;
        k++;
    }
}

void mergeSort(Cbasic Data[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(Data, l, m);
        mergeSort(Data, m+1, r);
        merge(Data, l, m, r);
    }
}

void menu()
{
    printf("\n==============Menu==============\n");
    printf("1. Doc file\n");
    printf("2. Tim kiem\n");
    printf("3. Danh sach xuat sac\n");
    printf("4. Ghi file\n");
    printf("5. Gop danh sach\n");
    printf("6. Exit\n");
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
                    Cbasic * tmpF = NULL;
                    Cbasic * tmpL = NULL;
                    NodeType p = readFileLL("6D.txt", tmpF, tmpL);
                    first6D = p.head;
                    last6D = p.tail;
                    printf("Class 6D: \n");
                    viewLL(first6D);
//                    viewLL2(first6D);

                    tmpF = NULL;
                    tmpL = NULL;
                    p = readFileLL("6E.txt", tmpF, tmpL);
                    first6E = p.head;
                    last6E = p.tail;
                    printf("Class 6E: \n");
                    viewLL(first6E);
//                    viewLL2(first6E);
                }
                printf("\nEntering data completely\n");
                break;
            case '2':
                {
                    int x;
                    printf("Enter x to execute the program: ");
                    scanf("%d", &x);
                    searchBiggerX(first6D, x);
                    searchBiggerX(first6E, x);
                    if (cntBiggerX == 0) printf("No students have higher score than %d", x);
                }
                printf("\nSearching completely\n");
                break;
            case '3':
                {
                    exLL(first6D, last6D, 8.5);
                    exLL(first6E, last6E, 8.5);
                    viewLL2(firstEx);
                }
                printf("\nSorting excellent stu completely\n");
                break;
            case '4':
                {
                    writeFile("Excellent.txt", firstEx);
                }
                printf("\nWriting Excellent list to file completely\n");
                break;
            case '5':
                {
                    firstEx = NULL;
                    lastEx = NULL;
                    exLL(first6D, last6D, 0);
                    exLL(first6E, last6E, 0);
                    int ln = enterData(Data, firstEx);
                    mergeSort(Data, 0, ln - 1);
                    for (int i = 0; i < ln; i++)
                    {
                        printf("%-20s%.1f\n", Data[i].name, Data[i].score);
                    }
                }
                break;
            case '6':
                printf("\nProgram is shutting down---\n");
                exit(0);
            default:
                printf("\nInvalid option, dear admin\n");
                break;
            }
        }
    }
}

