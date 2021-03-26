#include <unistd.h>
#include "my_print.h"

void my_putchar(char c)
{
  write(1, &c, 1);
}

void my_putstr(const char *str)
{
	int car;
	car = 0;
	
	while(str[car] != '\0'){
		my_putchar(str[car]);
		car++;
	}
}