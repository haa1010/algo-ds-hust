#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
/*typedef struct{
  
  };*/

void MENU()
{
  printf("============\nMENU\n");

  printf("1. \n");

  printf("2. \n");

  printf("3. \n");

  printf("4. \n");

  printf("5. \n");

  printf("6. Quit\n");
}
void clear_buffer()
{
  while(getchar()!='\n');
}
int main()
{
  int choice;
  char input[50];
  int while_condition = 1;
  do
    {
      MENU();
      printf("Your choice is :");
      scanf("%s", input);
      clear_buffer();
      choice = atoi(input);

      switch (choice)
        {
        case 1:

	  
	  break;

        case 2:

	  
	  break;

        case 3:

	  
	  break;

        case 4:

	  
	  break;

        case 5:

	  
	  break;

        case 6:
	  while_condition = 0;
	  break;

        default:
	  printf("Wrong choice !!\n Please choose again !!\n");
	  break;
        }

    } while (while_condition);
  return 0;
}



