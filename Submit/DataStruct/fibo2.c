#include <stdio.h>

long long fibo(int n)
{

    long long int pre, curr, next;

    while (next <= 4000000)
    {
        if (n == 1 || n == 2)
        {

            return 1;
        }
        if (next)
            return next;
        next = fibo(n - 1) + fibo(n - 2);

        return next;
    }
}

long long sum(int n)
{
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (fibo(i) % 2 == 0)
            ans += fibo(i);
    }
    return ans;
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%lld", sum(n));

    return 0;
}