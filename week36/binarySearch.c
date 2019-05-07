#include<stdio.h>
int n, x, a[10001];

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

int binarySearch(int L, int R)
{
    if (L == R)
    {
        if (a[L] == x)
            return 1;
        return 0;
    }
    int m = (L + R)/2;
    if (a[m] == x)
        return 1;
    if(a[m]>x) return binarySearch(L,m-1);
    else return binarySearch(m+1,R);
}

int main()
{
    scanf("%d %d\n",&n, &x);
    for(int i =1; i <=n ; i++)
    {
        scanf("%d",&a[i]);
    }
     quickSort(a,1, n);
    printf("Result : %d\n",binarySearch(1,n));
    return 0;
}

