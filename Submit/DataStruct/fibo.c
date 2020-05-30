#include <stdio.h>

long long  fibo()
{

    int prev = 2;
    int curr =8;
    int next = 0;
    long long sum=10;
    while (curr <= 4000000)
    {
        next = 4*curr + prev;
            
        prev = curr;
        curr = next;
       // if(curr%2 == 0)
         //   sum+= curr;
         if(curr <= 4000000)
         sum+= curr;
    }
    return sum;
}

int main()
{
   
    printf("%lld", fibo());
    return 0;
}