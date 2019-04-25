
// #include <stdio.h>
// int n, m, cnt = 0;
// int arr[1000], x[1000], appear[1000] = {0};
// int check(int v, int k)
// {
//     return ((appear[v] == 0));
// }

// void solution()
// {
//     int sum = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         if (arr[i] == 1)
//         //         {
//         //             sum+=x[i];
//         //         }
//         // }
//         // if(sum<=m&&sum!=0)
//         //     {cnt++;printf("sum is %d\n", sum);}
       
//     }
// }

// void Try(int k)
// {
//     int v;
//     for (v = 0; v <= 1; v++)
//     {
//         if (check(v, k))
//         {
//             arr[k] = v;
//             appear[v] = 1;
//             if (k == n)
//                 solution();
//             else
//                 Try(k + 1);
//             appear[v] = 0;
//         }
//     }
// }

// int main()
// {
//     scanf("%d %d", &n, &m);
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &x[i]);
//     }
//     Try(1);
//     printf("%d", cnt);
//     return 0;
// }


#include <stdio.h>
int n,m, cnt=0, sum;
int arr[1000], x[1000];
int check(int v, int k)
{
    return 1;
}

void solution()
{
    for (int i = 1; i < n; i++)
    {
        if((arr[i]==1)&&(arr[i+1]==1))
            {
                sum+=x[i];}
    }
    printf("\n");
    if((sum<=m) && (sum!= 0)) {printf("%d ",x[i]);cnt++;printf("cnt af %d\n",cnt);}
}

void Try(int k)
{
    int v;
    for (v = 0; v <= 1; v++)
    {
        if (check(v, k))
        {
            arr[k] = v;
            if (k == n)
                solution();
            else if(sum<n)
                Try(k + 1);
            sum =0;
        }
    }
}

int main()
{
    scanf("%d %d ", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x[i]);
    }
    Try(1);
    cnt/=2;
    printf("%d", cnt);
    return 0;
}