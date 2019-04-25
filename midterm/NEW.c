#include <stdio.h>
int n, m;
int a[500000];
int main()
{
    int b = 1, c = 1;
    int temp = 0, cnt = 0, sum = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    int d = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum += a[i];
        if (sum <= m)
        {
            temp++;
            if (c)
            {
                b = i;
                c = 0;
            }
        }
        else
        {
            cnt += ((temp * (temp + 1)) / 2 - (d * (d + 1)) / 2);
            temp = sum = 0;
            if (a[i] <= m)
            {
                d = i - b - 1;
                i = b;
            }
            else
            {
                d = 0;
                b = i;
            }
            c = 1;
        }
    }
    if (sum <= m)
    {
        cnt += ((temp * (temp + 1)) / 2 - (d * (d + 1)) / 2);
    }
    printf("%d\n", cnt);
    return 0;
}