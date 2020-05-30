#include <stdio.h>
#include <stdlib.h>
 long long int mark[100001] = {0};
 long long int common( long long int *arr,  long long int *brr,  long long int n,  long long int m)
{

     long long int dem = 0;
     long long int count[100001] = {0};
    for ( long long int i = 0; i < n; i++)
    {
        count[arr[i]] = arr[i];
    }
    for ( long long int j = 0; j < m; j++)
    {
        if (count[brr[j]] != 0 && mark[brr[j]] == 0)
        {
            dem++;
            mark[brr[j]]++;
        }
    }
    return dem;
}

int main()
{
     long long int n, m;
    scanf("%lld %lld", &n, &m);
     long long int *arr = ( long long int *)malloc(n * sizeof( long long int));
     long long int *brr = ( long long int *)malloc(m * sizeof( long long int));

    for ( long long int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    for ( long long int j = 0; j < m; j++)
    {
        scanf("%lld", &brr[j]);
    }

    printf("%lld\n", common(arr, brr, n, m));
    free(arr);
}
