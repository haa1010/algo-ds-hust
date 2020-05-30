#include <stdio.h>
#include <stdlib.h>
#define mod 1000000007
long long int m;
long long int n;
long long int a[1000001];

long long int cnt = 0;
void calculate()
{
    
    for (long long int i = 1; i < n; i++)
    {
        if(a[i]>m) continue;
        for (long long int j = i + 1; j <= n; j++)
        {
           if(a[j]>m) continue;
            if ((a[i] + a[j]) <= m)
                cnt= ((cnt%mod )+1)%mod;
        }
    }
}
int main()
{
    scanf("%lld %lld", &n, &m);
    for (long long int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    calculate();
    printf("%lld", cnt%mod);
    return 0;
}