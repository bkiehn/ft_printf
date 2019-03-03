#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int d = 10;
	char *s = "Hello";
	double f = -50.45916;
	char c = '2';

	printf("mine:%d\n",ft_printf("%-.2s is a string\n", ""));
	printf("lib:%d\n",printf("%-.2s is a string\n", ""));
	
}