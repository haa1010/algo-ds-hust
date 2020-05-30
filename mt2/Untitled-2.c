#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char P[1000];
int main(){
    int cnt = 0,ans;
    scanf("%s",P);
    while(1){
        char str[100001];
        gets(str);
        if(strcmp(str,"#") == 0) break;
        int j=0;
        for(int i=0;i<strlen(str);i++){
            if(str[i] == P[j] && P[j] != '\0'){
                j++;
                if(P[j] == '\0') cnt++;
                continue;
            }
            else{
                j = 0;
                continue;
            }
        }
    }
    // ans = match(P);
    printf("%d:%d\n",cnt,ans);
    return 0;
}