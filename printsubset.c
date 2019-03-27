#include<stdio.h>
int arr[1000];
int n;

int check(int v, int k)
{
    return 1;
}
void solution()
{
    for(int i = 1; i<=n ; i++)
    {
        if(arr[i]==1)
            printf("%d, ", i);
    }
    printf("\n");
}

void Try(int k)
{
    for(int v = 0 ; v<=1 ; v++)
    {
        if(check(v,k))
        {
            arr[k]=v;
            
            if(k==n) solution();
            else Try(k+1);
         
        }
    }
}

int main()
{
    scanf("%d",&n);
    Try(1);
    return 0;
}