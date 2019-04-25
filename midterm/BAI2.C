#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

long int n;
int a[1000000];
int appear[1000000] = {0};
int max;

int main()
{
    int i;
    scanf("%ld", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        appear[a[i]]++;
    }
   
    max = appear[a[0]];
    for (i = 0; i < n; i++)
    {
        if (max <= appear[a[i]])
        {
            max = appear[a[i]];
        }
    }
    printf("%d\n", max);
    return 0;
}