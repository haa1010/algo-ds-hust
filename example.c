#include<stdio.h>
int main()
{
	double a;
	double* p;
	p = &a;
	*p = 123.1;
	printf("a = %.2f\n", a);
	printf("p = %p\n", p);
	printf("address of a = %p\n size of a = %d , size of p = %d\n", &a, sizeof(a), sizeof(p));
	
	
}