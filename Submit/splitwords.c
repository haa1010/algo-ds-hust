#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<fstream>
#define MAX 1000
int main()
{   
    char s[1000];
    FILE* f = fopen("SPLITWORDS.INP", "r");
    FILE* fout = fopen("SPLITWORDS.OUT", "w");
    while(!feof(f))
    {
        fscanf(f, "%s" , s);
        if(strcmp(s, "#")== 0 ) break;
        fprintf(fout, "%s\n",s);
        
    }
    fclose(f);
    fclose(fout);
    return 0;
}

