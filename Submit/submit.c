#include <stdio.h>
int n, sum = 0;
int arr[1000];

int cnt = 0;

void Try(int k)
{
    int v;
    for (v = 1; v <= n; v++)
    {
        if (v>=arr[k-1])
        {
            arr[k]=v;
            sum+=v;           
            if (sum==n)
                cnt++;
            else if (sum < n)
                Try(k + 1); 
            sum-=v;
        }
    }
  
}

int main()
{
    scanf("%d", &n);
    Try(1);
      printf("%d", cnt);
    return 0;
}