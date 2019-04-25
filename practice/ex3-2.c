#include <stdio.h>

int m, n, l, r, cnt = 0, sum = 0;
int a[100] = {0};
void count()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            printf("%d %d = %d | %d - %d >= %d & %d - %d <= %d | ", i, j, a[j] - a[i - 1], a[j], l, a[i - 1], a[j], r, a[i - 1]);
            if ((a[j] - l >= a[i - 1]) && (a[j] - r <= a[i - 1]))
            {
                cnt++;
                printf(" C \n");
                continue;
            }
            printf(" N \n");
        }
    }
}

int main()
{
    scanf("%d %d %d ", &n, &l, &r);
    printf("%d %d \n", l, r);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        printf("%d\t", a[i]);
        a[i] = a[i] + a[i - 1];
    }
    printf("\n\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");

    count();
    printf(" result %d\n", cnt);
    return 0;
}