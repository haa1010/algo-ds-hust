#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cnt = 0;
char p[100001];
void occur(char *t)
{
    int lenp = strlen(p);
    int lent = strlen(t);
    //printf("p[0] = %c\n string len %d\n",p[0], lenp);
    if (strcmp(t, p) == 0)
    {
        cnt++;
       // printf("%d cnt\n", cnt);
    }
    else
    {
        for (int i = 0; i < lent; i++)
        {
           // printf(" t[%d] = %c\n",i, t[i]);

            if (t[i] == p[0])
            {
                int index_p = 0;
                int j = i;
                int same = 0;
                while (p[index_p] == t[j])
                {
                    if(index_p>=lenp) break;
                    if(j>lent)
                    same++;
                    j++;
                    index_p++;
                    //printf("same = %d\n",same);
                }
                if (same == lenp)
                {
                    cnt++;
                   // printf("%d cnt\n", cnt);
                }
            }
        }
    }
}

int main()
{
    int cnt = 0;
    printf("p : ");
    gets(p);
    while (1)
    {
        char t[100001];
        printf("t : ");
        gets(t);
        if (strcmp(t, "#") == 0)
            break;
        occur(t);
        printf("...\n");
    }
    printf("%d", cnt);
    return 0;
}