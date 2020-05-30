#include <stdio.h>



int check(int k, int v)
{
    return 1;
}

void solution(int n,int* arr)
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

void Try(int k, int n, int arr[1000])
{
    
    for (int v = 0; v <= 1; v++)
    {
        if (check(k, v))
        {
            arr[k] = v;
            if (k == n)
            {
               solution(n, arr);
            }
            else
                Try(k + 1, n, arr);
        }
    }
}

void result(int n)
{
    int arr[1000];
    Try(1, n, arr);
}

int main()
{
    int n;
    scanf("%d", &n);
    result(n);
    return 0;
}