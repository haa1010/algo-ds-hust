#include<stdio.h>
int x[8];
// SEND + MORE = MONEY
int appear[10] = {0}; 
int check(int v, int k)
{
	if(k==0 || k==4)
		if (v==0) 
			return 0;
	if(appear[v]==1)
		return 0;
	return 1;
}

void solution()
{
	int a = x[0]*1000+ x[1]*100 + x[2]*10 + x[3];
	int b = x[4]*1000+ x[5]*100 + x[6]*10 + x[1];
	int c = x[4]*10000+ x[5]*1000 + x[2]*100 + x[1]*10 + x[7];  
	if(a+b==c)
		printf("%d + %d = %d \n", a,b,c);	
}

void Try(int k)
{
	int v;
	for(v=0;v<=9;v++)
	{
		if(check(v, k))	
		{
			x[k]=v;
			appear[v]=1;
			if(k==7)
				solution();
			else 
				Try(k+1);
			appear[v]=0;
		}
	}

}
int main()
{
	Try(0);
}