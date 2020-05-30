#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int a[1000];
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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void maxHeapify(int n, int i)
{
    int l, r, largest;
    largest = i;
    l = 2 * i + 1;
    r = 2 * i + 2;
    if (l < n && a[l] > a[largest])
    {
        largest = l;
    }
    if (r < n && a[r] > a[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(&a[i], &a[largest]);
        maxHeapify(n,largest);
    }
}


void heapSort()
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(n,i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&a[0], &a[i]);
        maxHeapify(i,0);
    }
}

int main()
{
    genData("in",10);
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Before sorting : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    heapSort();
    printf("\nAfter sorting : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    return 0;
}
