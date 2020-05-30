#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct subStringInfo_s
{
    int index;
    int len;
} SubStringInfo;

#define MAX_N 1000
int p[MAX_N][MAX_N] = {0};
int n;
SubStringInfo maxSubStr(char *s)
{
     n = strlen(s);
    int maxlenth = 0;
    int beginIndex = 0;
    SubStringInfo res;
    for (int i = n; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
            {
                p[i][j] = 1; //base cases
            }
            else if (j == i + 1 || j == i + 2)
            {
                p[i][j] = s[i] == s[j];
            }
            else
            {
                p[i][j] = (s[i] == s[j]) && p[i + 1][j - 1];
            }
            if (p[i][j])
            {
                printf("index: %d. to %d\n", i, j);
                for (int k = i; k <=  j ; k++)
                {
                    printf("%c", s[k]);
                }
                printf("\n");
            }
            if (p[i][j] && (j - i + 1) >= maxlenth)
            {
                maxlenth = j - i + 1;
                beginIndex = i;
            }
        }
    }

    res.index = beginIndex;
    res.len = maxlenth;
    return res;
}

int main()
{

    SubStringInfo res = maxSubStr("abaabab");
for(int i = 0; i<n;i++)
{for(int j = 0;j<n;j++)
printf("%d ", p[i][j]);
printf("\n");}
}
