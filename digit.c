
#include <stdio.h>
int n, s;
int arr[1000];
int appear[1000]={0};
int check(int v, int k)
{
    return appear[v];
}

int  solution()
{
  return arr[5]*1000 + (arr[1]-arr[4]+arr[6])*100 + (arr[2]+arr[7])*10 + 2*arr[3]-62==n;
}
int cnt = 0;
void Try(int k)
{
    int v;
    
    for (v = 1; v <= 9; v++)
    {
        if (!check(v, k))
        {
            arr[k] = v;
            appear[v]=1;
            if (k == 7)
            {
                cnt += solution();                   
            }
            else
                Try(k + 1);
            appear[v]=0;
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