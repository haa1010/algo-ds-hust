#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void normalize(char * s)
{
    if(s[strlen(s)-1]==10)
    s[strlen(s)-1]='\0';
}
int main()
{
    char s1[50],s2[50], s3[50];
    FILE* f =fopen("get","r");
    FILE* fo = fopen("out", "w");
    while(!feof(f)){//fscanf(f,"%s", s1);
    //normalize(s1);
    fgets(s2,sizeof s2 , f);
    normalize(s2);
    fscanf(f,"%[^\n]\n",s3);
    
    fprintf(fo,"s2 : %s\ns3 : %s\n",s2,s3);
    }fclose(f);fclose(fo);
    return 0;
}