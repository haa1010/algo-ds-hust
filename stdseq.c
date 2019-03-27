#include<stdio.h>
#include<stdlib.h>
int n;
void ans(int *a)
{
  for(int i = 0 ; i < n ; i++)
  {
      if(a[i]!=a[i+1])
        printf("%d", a[i]);
  }
}

int main()
{
    scanf("%d",&n);
    int* a = (int*) malloc( n * sizeof(int));
    for(int i = 0 ; i < n ; i++)
        scanf("%d", &a[i]);
    ans(a);
    return 0;
}