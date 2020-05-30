#include <stdio.h>
#include <stdlib.h>
#define mod 1000000007
long long int x;
long long int n;
long long int a[1000001];
long long int cnt = 0;

void swap(long long int *c, long long int *b)
{
    long int temp = *c;
    *c = *b;
    *b = temp;
}

long long int partition(long long int low, long long int high)
{
    long long int pivot = a[high];
    long long int i = low - 1, j;
    for (j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return i + 1;
}

void quickSort(long long int low, long long int high)
{
    if (low < high)
    {
        long long int p = partition(low, high);
        quickSort(low, p - 1);
        quickSort(p + 1, high);
    }
}

void calculate(long long int m)
{
    for (long long int i = 1; i < n; i++)
    {
        if (a[i] > m)
            break;
        for (long long int j = i + 1; j <= n; j++)
        {
            if (a[j] > m)
                break;
            if ((a[i] + a[j]) == m)
                cnt = ((cnt % mod) + 1) % mod;
        }
    }
}
int main()
{
    scanf("%lld %lld", &n, &x);
    for (long long int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    quickSort(1, n);

    for (long long int i = 1; i <= n; i++)
    {
        calculate(a[n - i]);
    }
    printf("%lld", cnt % mod);
    return 0;
}