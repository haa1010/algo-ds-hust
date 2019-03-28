#include<stdio.h>
int a[100][100]={0};
int ckn(int k , int n)
{
    if(k==0 || k==n)
        return 1;
    if(a[k][n])
        return a[k][n];
    a[k][n] = ckn(k-1,n-1) + ckn(k, n-1);
    return a[k][n];
}

int main()
{
    int k, n;
    scanf("%d %d",&k,&n);
    printf("%d\n",ckn(k,n));
    return 0;
}