#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 10000

int countNaive(char *t, char *s)
{
    int c = 0;
    int m = strlen(s);
    int n = strlen(t);
    for (int i = 0; i <= n - m; i++)
    {
        int ok = 1;
        for (int j = 0; j < m; j++)
        {
            if (s[j] != t[j + i])
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
    char filename[max];
    //gets(filename);
    FILE *f = fopen("i.txt", "r");
    while (!feof(f))
    {
        char t[max];
        fgets(t, sizeof t, f);
        if (t[strlen(t) - 1] == 10)
            t[strlen(t) - 1] == '\0';
        if (strcmp(t, "#") == 0)
            break;
        int i = 0;
        char s[max];
        while (i < strlen(t))
        {
            while (i < strlen(t) && (t[i] == ' ' || t[i] == '\t' || t[i] == '.' || t[i] == ','))
                i++;
            int j = 0;
            while (i < strlen(t) && t[i] != ' ' && t[i] != '\t' && t[i] != '.' && t[i] != ',')
            {
                s[j] = t[i];
                j++;
                i++;
            }
            s[j] = '\0';
            printf("%s\tappears %d\n", s, countNaive(t, s));
        }
    }
    fclose(f);

    return 0;
}