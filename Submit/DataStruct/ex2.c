#include <stdio.h>
int n;
int arr[100];
int appear[100];

void init()
{
    for (int i = 0; i <= n; i++)
        appear[i] = 0;
}

int check(int v)
{
    return appear[v];
}

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

void result(int k)
{
    for (int v = 1; v <= n; v++)
    {
        if (!check(v))
        {
            arr[k] = v;
            appear[v] = 1;
            if (k == n)
            {
                solution();
            }
            else
            {
                result(k + 1);
              }
             appear[v] = 0;
        }
    }
}

int main()
{
    init();
    scanf("%d", &n);
    result(1);
    return 0;
}