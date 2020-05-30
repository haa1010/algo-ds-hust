#include <stdio.h>
#include <math.h>

void foo() {
	char str[80];
	sprintf(str, " abc %f", M_PI);
	puts(str);
}

int main () {
   foo();
   return(0);
}
