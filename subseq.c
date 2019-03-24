
#include <stdio.h>
int n, s;
int arr[1000];
int check(int v, int k)
{
    return 1;
}

int  solution()
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if(arr[i]==1)
        {
            sum+=i;
        }

    }
    return sum == s;
}
int cnt = 0;
void Try(int k)
{
    int v;
    
    for (v = 0; v <= 1; v++)
    {
        if (check(v, k))
        {
            arr[k] = v;
            if (k == n)
            {
                cnt += solution();                   
            }
            else
                Try(k + 1);
        }
    }
}

int main()
{
    scanf("%d%d", &n, &s);    
    Try(1);
    printf("%d", cnt);
    return 0;
}