#include<stdio.h>
int a[1000];
int x, cnt=0, sum = 0;
int appear[1000]={0};
int check(int v, int k)
{
    if(k==1 || k==3 || k ==6 )
		if (v==0) 
			return 0;
	if(appear[v]==1)
		return 0;
	return 1;
}
void solution()
{
    //sum = a[6]*1000 + (a[3]*2+a[5])*100 + (a[1]+a[2]+a[4]+a[7])*10 + a[2]+a[5]+a[8]+a[9];
    sum = a[1]*10 + a[2] + a[3]*100 + a[4]*10 + a[5] + a[6]*1000 + a[5]*100 + a[7]*10 + a[8] + a[3]*100 + a[2]*10 +a[9];
    if(sum==x)
        cnt++;
        
}

void Try(int k)
{
    int v;
    for(v=0; v<=9; v++)
    {
        if(check(v,k))
        {
            a[k]=v;
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
    scanf("%d",&x);
    Try(1);
    printf("%d",cnt);
    return 0;
}
