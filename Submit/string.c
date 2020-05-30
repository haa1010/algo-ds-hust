#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char* trim_right(char *a);
void trim_left(char *a);
char *trim_middle(char *a);
int get_space_left(char*a);
int get_space_right(char*a);
void get_string(char *a);
void MENU();
int get_choice();
int main(){
  int while_condition=1;
  char a[100];
  get_string(a);
  
  do{
    MENU();
    int choice = get_choice();
    switch(choice){
    case 1:
      printf("Your string is:\n%s\nYour string after eliminate all spare blanks in the middle is:\n",a);
      trim_right(a);
      printf("%s\n",a);
      break;
    case 2:
      trim_left(a);
      break;
    case 3:
      printf("Your string is:\n%s\nYour string after eliminate all spare blanks in the middle is:\n",a);
      trim_middle(a);
      printf("%s\n",a);
      break;
    case 4 :
      while_condition=0;
      break;
    }
  }while(while_condition);
}

void MENU(){
  printf("========================================================\nMENU\n");
  printf("1. Eliminate the blanks at the end of string\n");
  printf("2. Eliminate the blanks at the begin of string\n");
  printf("3. Eliminate the closed blanks at the middle of string\n");
  printf("4. Quit\n");
}
int get_choice(){
  char input[100];
  do{
    printf("Your choice is ");
    gets(&input);
    int choice = atoi(input);
    if ((choice>0)&&(choice<5))
      return choice;
    printf("---Invalid input. Try again\n");
  }while(1);
}

void get_string(char a[]){
  printf("Enter your string :");
  gets(a);
}

int get_space_left(char *a)
{
  int i;  
  for ( i=0; a[i]!='\0';i++)
    if(*(a+i)!=' ')
      return i;
}

  
void trim_left(char *a){
  char* p = a ;
  int i;
  int len = strlen(p);
  int x = get_space_left(a);
  printf("---Your string is :\n%s\n",a);
  printf("---Your string after eliminate all blanks at the begin is :\n" );
  for( i = x; (i<len) ; i++)
      printf("%c",*(p+i));
  printf("\n");
}

char* trim_right(char *a){
  int i;
  int len=strlen(a);
  int x = get_space_right(a);
  printf("---Your string is :\n%s\n",a);
  printf("---Your string after eliminate all blanks at the end is :\n" );
  //  for( i = 0; (i<=x) ; i++)
  //  printf("%c",*(p+i));
  //printf("%c\n",*(p+len-1));


  for(i=0;i<len;i++)
    if(a[len-1] != ' '){a[x+1] = a[len-1];a[x+2] = 0;}
    else a[x+1]=0;
  return a;
}

int get_space_right(char* a){
  int i;
  int len = strlen(a);
  if (a[len-1] != ' ')
    {
    for( i = len - 2; i>=0; i--)
      if ( a[i] != ' ')
	return i;
    }
  for( i = len - 1; i>=0; i--)
    {
    if ( a[i] != ' ')
      return i;
    }
}
      

char *trim_middle(char *a)
{
  int r; 
  int w; 
  r=w=0;
  while (a[r])
  {
    if (isspace(a[r]))
    {
      if (w > 0 && !isspace(a[w-1]))
        a[w++] = ' ';
    }
    else
      a[w++] = a[r];
    r++;
  }
  a[w] = 0;
  return a;
}