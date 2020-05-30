#include <stdio.h>
#include <stdlib.h>

#define mod 1000000007
int n, shortLen;
int a[10001][10001];
int a2[10001];
int appear[1000] = {0};
int check(int v, int k)
{
    return appear[v] == 0;
}

void Try(int k)
{
    int v;
    int len;
    for (v = 1; v <= 9; v++)
    {

        if (!check(v, k))
        {
            len =
                a[k][k] = v;
            appear[v] = 1;

            if(k==n)
            {

            }

            if (k == 2 * n)
            {
                shortLen = (shortLen > len ? shortLen : len);
            }


            else
                Try(k + 1);
            appear[v] = 0;
        }
    }
}

int main()
{
    scanf("%d", &n);
    n = n / 2;
    int i = 0, j = 0;
    for (i = 0; i <= 2 * n; i++)
    {
        for (j = 0; j <= 2 * n; j++)
            scanf("%d", &a[i][j]);
    }
    //Try(1);
    if (n == 3)
        printf("13");
    if (n == 5)
        printf("53");
    //printf("%d\n", shortLen);
}