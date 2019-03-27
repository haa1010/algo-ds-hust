#include<stdio.h>
#define size 9
int x[size][size], x2[9][9];  //solution representation
int r[9][10]={0};  //r[i][v]=1 if v appearred in row i
int c[9][10]={0};  //c[j][v]=1 if v appearred in column j
int d[3][3][10]={0}; //d[I][J][v]=1 if v appearred in subsquare [I,J] I,J = [0;2]

void init()
{
	
	for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{	
				int v = x[i][j];
				if(v!= 0)
				{
					r[i][v]=1;
					c[j][v]=1;
					d[i/3][j/3][v]=1;
				}
			}
		}	
	
}

int check(int v, int i, int j)
{
	
	return r[i][v]==0 && c[j][v] ==0 && d[i/3][j/3][v]==0;	
}

void solution()
{
	int i,j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			printf("%d  ",x[i][j]);
		}
		printf("\n");
	}
	printf("\n");	
}


void sudoku(int i , int j)
{

	if(x2[i][j]>0)
	{
		if(i==8 && j==8)
		{
			solution();
		}
		else
		{
			if(j==8)
				sudoku(i+1,0);
			else
				sudoku(i,j+1);
		}
		return ;
	}
	else
	{
		int v;
		for(v=1;v<=9;v++)
		{
			if(check(v,i,j))
			{
				x[i][j]=v;
				//mark the appearance of v 
				r[i][v]=1;
				c[j][v]=1;
				d[i/3][j/3][v]=1;

				if(i==8 && j==8)
				{
					solution();
				}
				else 
				{
					if(j==8)
						sudoku(i+1,0);
					else
						sudoku(i,j+1);
				}
				//recover
				r[i][v]=0;
				c[j][v]=0;
				d[i/3][j/3][v]=0;
			}
		}
	}
}
int main()
{
	FILE* f = fopen("sudokuinput.txt","r");
	for(int i = 0 ; i < 9; i++)
		for( int j=0; j < 9 ;j++)
			{
				fscanf(f,"%d",&x[i][j]);
				x2[i][j]=x[i][j];
			}
	init();
	
	sudoku(0,0);
	fclose(f);
	return 0;
}