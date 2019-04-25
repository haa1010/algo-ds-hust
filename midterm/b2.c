#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, appear[100000] = {0};
    //long long int *a = (long long int *)malloc(n * sizeof(long long int));
    int a[1000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (appear[a[i]] != 0)
        {
            appear[a[i]]++;
        }
        else
        {
            appear[a[i]] = 1;
        }
    }
    int max = appear[a[0]], index = 0;

    for (int i = 1; i < n; i++)
    {
        if (appear[a[i]] > max)
        {
            max = appear[a[i]];
            index = a[i];
        }
    }
    printf("%d", max);
    return 0;
}