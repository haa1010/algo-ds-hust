#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 100001
char p[max], t[max];
int last[256] = {0};
int computeLast(int n, int m)
{
    for (int i = m - 1; i >= 0; i--)
    {
        if (last[p[i]] == 0)
            last[p[i]] = i;
    }
}

int s = 0, c = 0;
int boyerMoore(int n, int m)
{
    computeLast(n, m);
    while (s <= n - m)
    {
        int j = m - 1;
        while (j >= 0 && t[j + s] == p[j])
            j--;
        if (j == -1)
        {
            s++;
            c++;
        }
        else
        {
            int k = last[t[j + s]];
            s = s + (j - k > 1 ? j - k : 1);
        }
    }
}
int main()
{
    
    FILE *f = fopen("inputString", "r");
    {
        fgets(p, max, f);
        if (p[strlen(p) - 1] == 10)
            p[strlen(p) - 1] = '\0';
        fgets(t, max, f);
        if (t[strlen(t) - 1] == 10)
            t[strlen(t) - 1] = '\0';
    }
    int m = strlen(p);
    int n = strlen(t);
    boyerMoore(n, m);
    printf("%d", c);
    return 0;
}