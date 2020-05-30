#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 100
int cnt = 1;
int countString(FILE* f)
{
    char p[max];
    while (1)
    {
        fgets(p, max, f);
        if (p[strlen(p) - 1] == 10)
            return cnt;
        if (p[strlen(p) - 1] == 44 || p[strlen(p) - 1] == 46 || p[strlen(p) - 1] == 9 || p[strlen(p) - 1] == 32)
            cnt++;
    }
}
char t[max];
void splitString(FILE *f)
{
    fgets(t, max, f);
    if (strcmp(t, ".") == 0 || strcmp(t, ",") == 0 || strcmp(t, "\t") == 0)
    {
        t[strlen(t) - 1] = '\0';
    }
    printf(" %s\n", t);
}
int main()
{
    char filename[max];
    gets(filename);
    
    FILE *f = fopen(filename, "r");
    // for(int i = 0 ; i< cnt; i++)
    // {
        
    //     strcpy(t, splitString(filename));
    //     printf("%d %s\n",i+1, t);
    // }
    int c = countString(f);
    splitString(f);
    printf("cnt %d \n",c);
    fclose(f);
    return 0;
}