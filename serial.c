 #include<stdio.h>
 int a[1000];
 int n, sum=0;
void solution(int k)
{
    for(int i =1; i <= k ; i++)
        printf("%d ", a[i]);
    printf("\n");
}
void Try(int k)
{
    int v ;
    for(v=1;v<=n;v++)
    {
        if(v>=a[k-1])
        {
            a[k]=v;
            sum+=v;
            if(sum==n)
                solution(k);
            else if(sum<n)
                    Try(k+1);
            sum-=v;
        }
    }
}

int main()
{
    scanf("%d", &n);
    Try(1);
    return 0;
}