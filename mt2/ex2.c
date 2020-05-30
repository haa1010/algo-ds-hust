#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char p[100001];
int cnt = 0;
void occur(char *t)
{
    int lent = strlen(t);
    int lenp = strlen(p);
    for (int i = 0; i < len; i++)
    {
        if (t[i] == p[0])
        {
            int index_p = 1;
            int j = i + 1;
            int same = 1;
            while (1)
            {
                if (p[index_p] != t[j])
                    break;
                j++;
                index_p++;
                same++;
            }
            if (same == lenp)
                cnt++;
        }
    }
}

int main()
{
    gets(p);
    while (1)
    {
        char t[100001];
        gets(t);
        if (strcmp("#",t) == 0)
            break;
        occur(t);
        break;
    }
    printf("%d", cnt);
    return 0;
}