#include <stdio.h>
long long int n, m;
long long int x[1000];

int count()
{
    int cnt = 0;
    long long int ans;
    for (long long int i = 1; i <= n ; i++)
    {
        ans = x[i];
        if (x[i] <= m)
            cnt++;
        else continue;    

        for (long long int j = i + 1; j <= n; j++)
        {
            ans += x[j];
            if (ans <= m)
                {
                cnt++;}
            else
                {
                   break;
                   }
        }
    }
    return cnt;
}
int main()
{
    scanf("%lld %lld ", &n, &m);
    for (long long int i = 1; i <= n; i++)
    {
        scanf("%lld", &x[i]);
    }

    printf("%d", count());
    return 0;
}