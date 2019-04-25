#include <stdio.h>

int m, n, cnt = 0, sum = 0;
int a[100];
void count()
{
    for (int i = 1; i <= n; i++)
    {
        sum = a[i];

        if (sum > m)
            continue;
        cnt++;

        for (int j = i + 1; j <= n; j++)
        {
            sum += a[j];
            if (sum <= m)
                cnt++;
            else
                continue;
        }
    }
}

int main()
{
    scanf("%d %d ", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    count();
    printf(" result %d\n", cnt);
    return 0;
}