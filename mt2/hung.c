#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define maxn 1000030
 
char p[1000];
char t[2000][5000];
int q = 0, n = 0;
 
void clearBuffer () {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void input () {
    gets(p);
    char tmp[5000];
    gets(tmp);
    int i = 0;
    while (strcmp(tmp, "#") != 0) {
        strcpy(t[n++], tmp);
        gets(tmp);
    }
}
void output () {
    printf("%d\n", q);
}
 
int countLine (int k) {
    int lenp = strlen(p);
    int lent = strlen(t[k]);
    int occur = 0;
    for (int i = 0; i < lent; ++i) {
        int j = 0;
        int a = i;
        while ((j < lenp && a < lent) && t[k][a++] == p[j++]) {
        }
        if (j >= lenp)
            ++occur;
    }
 
    return occur;
}
 
void solve () {
    for (int i = 0; i < n; ++i) {
        q += countLine(i);
    }
}
 
int main () {
    input();
    solve();
    output();
    return 0;
}