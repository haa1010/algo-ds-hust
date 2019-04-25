#include <stdio.h>
#define maxn 200000

int n, m;
int a[maxn];

int main()
{
    int ml = 0, j = 1, f = 1;
    int cnt = 0;
    int subsum = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    int d = 0;
    for (int i = 1; i <= n; ++i)
    {
        subsum += a[i];
        if (subsum <= m)
        {
            ++ml;
            if (f)
            {
                j = i;
                f = 0;
            }
        }
        else
        {
            cnt += ((ml * (ml + 1)) / 2 - (d * (d + 1)) / 2);
            ml = 0;
            subsum = 0;
            if (a[i] <= m)
            {
                d = i - j - 1;
                i = j;
            }
            else
            {
                j = i;
                d = 0;
            }
            f = 1;
        }
    }
    if (subsum <= m)
    {
        cnt += ((ml * (ml + 1)) / 2 - (d * (d + 1)) / 2);
    }
    printf("%d\n", cnt);
}