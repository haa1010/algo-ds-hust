#include<stdio.h>
int n,cnt=0, sum=0;
int arr[1000], appear[1000]={0};
int check(int v, int k)
{
    return appear[v]==0;
}

void solution()
{
     sum=(arr[1]+arr[6]-arr[4])*100 + (arr[2]+ arr[7])*10 + 2*arr[3] + arr[5]*1000 ;
    if(sum==(n+62)) cnt++;
}

void Try(int k )
{
    int v ;
    for(v = 1; v <=9 ;v++)
    {
        if(check(v,k))
        {
            arr[k]=v;
            appear[v]=1;
            if(k==7)
                solution();
            else Try(k+1);  
            appear[v]=0; 
            sum=0; 
        }
    }
}

int main()
{
    scanf("%d", &n);
    Try(1);
    printf("%d",cnt);
    return 0;
}