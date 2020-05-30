#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

typedef struct data_s
{
    int maSP;
    char ten[30];
    int gia;
    int soluong;
} Data;

typedef struct Node
{
    Data data;
    struct Node *next;
} Node;

void MENU()
{
    printf("============\nMENU\n");

    printf("1. Nhap san pham\n");

    printf("2. Heap sort\n");

    printf("3. Linked list\n");

    printf("4. Merge sort\n");

    printf("5. Hien thi san pham\n");

    printf("6. Thoat\n");
}

int compare(Data a, Data b)
{
    return a.gia - b.gia;
}

void clear_buffer()
{
    while (getchar() != '\n')
        ;
}

Node *first;
Node *last;

Node *makeNode(int maSP, int gia, int soluong, char *ten)
{
    Node *p = (Node *)malloc(sizeof(Node)); //allocate memory for p
    p->data.maSP = maSP;
    p->data.gia = gia;
    p->data.soluong = soluong;
    strcpy(p->data.ten, ten);
    p->next = NULL;
    return p;
}

void addLast(int maSP, int gia, int soluong, char *ten)
{
    Node *p = makeNode(maSP, gia, soluong, ten);
    if (last != NULL)
        last->next = p;
    last = p;
    if (first == NULL)
        first = p;
}

void printList()
{
    for (Node *p = first; p != NULL; p = p->next)
        printf("%d %d %d %s\n", p->data.maSP, p->data.gia, p->data.soluong, p->data.ten);
}

void clearList()
{
    Node *toBeFree = NULL;
    for (Node *p = first;; p = p->next)
    {
        if (toBeFree)
        {
            free(toBeFree);
        }
        toBeFree = p;
        if (!p)
        {
            break;
        }
    }
}

void linkedList(char *filename)
{
    FILE *f = fopen(filename, "r");
    int maSP, gia, soluong;
    char ten[30];
    while (!feof(f))
    {
        fscanf(f, "%d %d %d %s\n", &maSP, &gia, &soluong, ten);
        addLast(maSP, gia, soluong, ten);
    }
    fclose(f);
}

void swap(Data *a, Data *b)
{
    Data temp = *a;
    *a = *b;
    *b = temp;
}

Data a[1000];
int n = -1;
void heapify(Data *a, int n, int i)
{
    int largest, l, r;
    largest = i;
    l = 2 * i + 1;
    r = 2 * i + 2;
    if (l < n && (a[l]).gia > a[largest].gia)
        largest = l;
    if (r < n && a[r].gia > a[largest].gia)
        largest = r;
    if (largest != i)
    {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(Data *a, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

void merge(Data *a, int p, int q, int r)
{

    int n1 = q - p + 1;
    int n2 = r - q;
    Data L[n1], R[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = a[i + p];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = a[i + q + 1];
    }
    int i = 0, j = 0;
    int k = p;
    while (i < n1 && j < n2)
    {
        if (L[i].gia >= R[j].gia)
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
void MS(Data *a, int p, int r)
{
    if (p < r)
    {
        int q = p + (r - p) / 2;
        MS(a, p, q);
        MS(a, q + 1, r);
        merge(a, p, q, r);
    }
}

void docSP(char *filename)
{
    FILE *f = fopen(filename, "r");
    Data tmp;
    char ten[30];
    while (!feof(f))
    {
        n++;
        fscanf(f, "%d %d %d %s\n", &tmp.maSP, &tmp.gia, &tmp.soluong, tmp.ten);
        memcpy(&a[n], &tmp, sizeof(Data));
    }
    fclose(f);
}

int nhapDuLieu(int x)
{
    int gia;
    while (1)
    {
        scanf("%d", &gia);
        if (gia > x)
            return gia;
        printf("Khong thoa man. Nhap lai : ");
    }
}

int check_valid_number(char *s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] > '9')
        {
            return 0;
        }
        if (s[i] < '0')
        {
            return 0;
        }
    }
    return 1;
}

void nhap(char *filename)
{
    FILE *f = fopen(filename, "w");
    int maTruoc = -10;
    while (1)
    {
        int maSP, gia, soluong, br = 0;
        char ten[30], input[30], id[30];
        printf("Nhap ma : ");
        while (1)
        {
            gets(id);
            int check = check_valid_number(id);
            maSP = atoi(id);
            if (!check)
            {
                br = 1;
                break;
            }
            if (maSP < 1)
            {
                br = 1;
                break;
            }
            if (maSP > maTruoc)
                break;
            printf("Khong thoa man. Nhap lai : ");
        }
        if (br)
            break;
        fprintf(f, "%d ", maSP);
        printf("Nhap gia : ");
        gia = nhapDuLieu(0);
        fprintf(f, "%d ", gia);
        printf("Nhap so luong : ");
        soluong = nhapDuLieu(-1);
        fprintf(f, "%d ", soluong);
        printf("Nhap ten : ");
        clear_buffer();
        gets(ten);
        fprintf(f, "%s\n", ten);
        //printf(f, "ma %d gia %d soluong %d ten %s matruoc %d\n",maSP, gia, soluong,ten,maTruoc);
        maTruoc = maSP;
    }
    fclose(f);
}

int main()
{
    int choice;
    char input[10];
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
            nhap("sanpham.txt");

            break;

        case 2:
            docSP("sanpham.txt");
            heapSort(a, n);
            FILE *f1 = fopen("heapsort.txt", "w");
            for (int i = 0; i < n; i++)
            {
                fprintf(f1, "%d %d %d %s\n", a[i].maSP, a[i].gia, a[i].soluong, a[i].ten);
            }
            fclose(f1);
            break;

        case 3:
            linkedList("sanpham.txt");
            printList();
            break;

        case 4:

            MS(a, 0, n - 1);
            FILE *f2 = fopen("mergesort.txt", "w");
            for (int i = 0; i < n; i++)
            {
                fprintf(f2, "%d %d %d %s\n", a[i].maSP, a[i].gia, a[i].soluong, a[i].ten);
            }
            fclose(f2);
            break;

        case 5:
        {
            char read[30];
            while (1)
            {
                printf("Nhap ten file de mo : ");
                gets(read);
                if (strcmp(read, "sanpham.txt") == 0 || strcmp(read, "heapsort.txt") == 0 || strcmp(read, "mergesort.txt") == 0)
                    break;
                printf("Khong co fle %s. Nhap lai.\n", read);
            }
            clearList();
            linkedList(read);
            printList();
            break;
        }

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
