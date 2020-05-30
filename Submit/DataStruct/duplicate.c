#include <stdio.h>
#define max 100000
int firstDuplicate(int *a)
{
    //
    int appear[max];

    for (int i = 1; i <= max; i++)
    {
        if (appear[a[i]] == 1)
            return a[i];
        appear[a[i]] = 1;
    }
    return -1;
}
int main()
{
    int n = 6;
    int a[n];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("%d",firstDuplicate(a));
}