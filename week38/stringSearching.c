#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 100001
char p[max], t[max];
int last[256];
int ans, c = 0;
int countNaive()
{
    int m = strlen(p);
    int n = strlen(t);
    for (int i = 0; i <= n - m; i++)
    {
        int ok = 1;
        for (int j = 0; j < m; j++)
        {
            if (p[j] != t[j + i])
            {
                ok = 0;
                break;
            }
        }
        if (ok)
            c++;
    }
    return c;
}

int main()
{
    // gets(p);
    // gets(t);
    FILE *f = fopen("inputString", "r");
    {
        fgets(p,max,f);
        if(p[strlen(p)-1]==10)
        p[strlen(p)-1]='\0';
        fgets(t,max,f);
        if(t[strlen(t)-1]==10)
        t[strlen(t)-1]='\0';
    }
    countNaive();
    printf("%d", c);
    return 0;
}