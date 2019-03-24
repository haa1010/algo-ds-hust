#include<stdio.h>
int n,s;
int arr[1000];
int appear[1000]={0};
int check(int v, int k)
{
    return appear[v];
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
    for(v = 1; v <=n ;v++)
    {
        if(!check(v,k))
        {
            arr[k]=v;
            appear[v]=1;
            if(k==n)
                solution();
            else Try(k+1);  
            appear[v] =0;  
        }
    }
}

int main()
{
    scanf("%d", &n);
    Try(1);
    return 0;
}