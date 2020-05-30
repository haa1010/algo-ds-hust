#include <stdio.h>
int n;
int arr[100] = {0};
int sum = 0;
int check(int v, int k)
{
    return v >= arr[k - 1];
}

void solution(int k)
{
    for (int i = 1; i <= k; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void result(int k)
{

    for (int v = 1; v <= n; v++)
    {
        if (check(v, k))
        {
            arr[k] = v;
            sum = sum + arr[k];
         
            if (sum == n && k <= n)
            {
                solution(k);
            }
            else if (sum < n)
            {
                result(k + 1);
            }
            sum = sum - arr[k];
        }
    }
}

int main()
{

    scanf("%d", &n);
    result(1);
    return 0;
}