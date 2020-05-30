#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define max 1000001
int a[max];
int n;

void genData(char* filename, int n)
{
    FILE* fo = fopen( filename, "w");
    fprintf(fo,"%d\n",n);
    srand(time(NULL));
    for(int i = 1; i<=n ; i++)
    {
        int x = rand()%1000000;
        fprintf(fo,"%d ",x);
    }
    fclose(fo);
}

void loadData(char* filename)
{
    FILE* f =fopen(filename, "r");
    fscanf(f,"%d",&n);
    for(int i = 1; i<=n ; i++)
    {
        fscanf(f,"%d",&a[i]);
    }
    fclose(f);
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int *a, int L, int R, int indexPivot)
{
    int pivot = a[indexPivot];
    swap(&a[indexPivot],&a[R]);
    int storeIndex = L;
    for(int i = L; i<=R-1; i++)
    {
        if(a[i]<pivot)
        {
            swap(&a[i],&a[storeIndex]);
            storeIndex++;
        }
    }
    swap(&a[storeIndex],&a[R]);
    return storeIndex;
}

void quickSort(int* a, int L, int R)
{
    if(L<R)
    {
        int index = (L+R)/2;
        index=partition(a,L,R,index);
        if(index>L) quickSort(a,L,index-1);
        if(index<R) quickSort(a,index+1,R);
    }
}

int main()
{
    genData("in",10);
    loadData("in");
    printf("Before sorting : ");
    for (int i = 1; i <= n; i++)
    {
        printf("%d\t", a[i]);
    }
    quickSort(a,1, n);
    printf("\nAfter sorting : ");
    for (int i = 1; i <= n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    return 0;
}