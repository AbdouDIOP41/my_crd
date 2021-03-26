void my_putchar(char c);
void my_putstr(const char *str)
{
	int car;
	car = 0;
	
	while(str[car] != '\0'){
		my_putchar(str[car]);
		car++;
	}
}