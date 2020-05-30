#include<stdio.h>
long long int a[100000];
long long int n;
long long int ans()
{
    long long int cnt=0;
    for(long long int i =0; i<n-1 ; i++)
    {
        for(long long int j=i+1; j<n; j++)
        {
            if(a[j]>a[i])
                cnt++;
        }
    }
    return cnt;
}

int main(){
    scanf("%lld",&n);
    for(long long int i =0 ; i<n ; i++)
    {
        scanf("%lld",&a[i]);
    }
    printf("%lld",ans());
    return 0;
}