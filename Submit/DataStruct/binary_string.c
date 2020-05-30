#include <stdio.h>
#include <stdlib.h>
/*
void binary_string(int n, int *arr)
{
    for(int i = n-1; (i>=0) && (arr[i]!= 0) ; i++)
    {
        arr[i]=1;

    }
}

void print(int arr)
{
    for (i = 1; i <= n; i++)
    {
        printf("%d", arr[i]);
    }
}

int main()
{
    int n;
    int *arr = (int *)malloc((n+1) * size of(int));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        arr[i] = 0;
    }
    print(arr));
    printf("\n");
    binary_string(n, arr);
    return 0;
}
*/
int n;
int arr[100];
int check(int v, int k)
{
    return 1;
}
void print(int* arr)
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

void binary_string(int k)
{
    for (int v = 0; v <= 1; v++)
    {
        if (check(v, k))
        {
            arr[k] = v;
            if (k == n)
                print(arr);
            else
                binary_string(k + 1);
        }
    }
}


int main()
{
  
    scanf("%d", &n);
    binary_string(1);
    return 0;
}
