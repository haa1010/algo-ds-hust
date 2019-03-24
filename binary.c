#include<stdio.h>
int n,s;
int arr[1000];
int check(int v, int k)
{
    return 1;
}

void solution()
{
    for(int i = 1 ; i <= n ;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}

void Try(int k )
{
    int v ;
    for(v = 0; v <=1 ;v++)
    {
        if(check(v,k))
        {
            arr[k]=v;
            if(k==n)
                solution();
            else Try(k+1);    
        }
    }
}

int main()
{
    scanf("%d", &n);
    Try(1);
    return 0;
}