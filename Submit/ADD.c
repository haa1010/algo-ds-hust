#include<stdio.h>
long int a, b;
long int add (long int a, long int b)
{
    return a+b;
}
int main()
{
    scanf("%ld %ld", &a, &b);
    printf("%ld", add(a,b));
    return 0;
}
