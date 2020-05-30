#include <stdio.h>
int a[100];
int n;
void swap(int *a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *a, int n, int i)
{
    int largest, l, r;
    largest = i;
    l = 2 * i + 1;
    r = 2 * i + 2;
    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;
    if(largest!=i)
    {
        swap(&a[i],&a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(int* a, int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(a,n,i);
    }

    for(int i = n-1; i>=0 ; i--)
    {
        swap(&a[0],&a[i]);
        heapify(a, i, 0);
    }
}

int main()
{
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Before sorting : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    heapSort(a,n);
    printf("\nAfter sorting : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    return 0;
}