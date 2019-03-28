#include<stdio.h>
int n,cnt=0, sum=0;
int arr[1000], appear[1000]={0};
int check(int v, int k)
{
    return appear[v]==0;
}

void solution()
{
      sum = arr[1]*10 + arr[2] + arr[3]*100 + arr[4]*10 + arr[5] + arr[6]*1000 + arr[5]*100 + arr[7]*10 + arr[8] + arr[3]*100 + arr[2]*10 +arr[9];
    if(sum==n) cnt++;
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
            if(k==9)
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