#include<stdio.h>
int a[10000];
int n;
int ans()
{
    int cnt=0;
    for(int i =0; i<n-1 ; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(a[j]>a[i])
                cnt++;
        }
    }
    return cnt;
}

int main(){
    scanf("%d",&n);
    for(int i =0 ; i<n ; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("%d",ans());
    return 0;
}