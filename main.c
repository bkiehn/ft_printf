#include "ft_printf.h"
#include <stdio.h>
#include <math.h>
#include <limits.h>


int main()
{
	char *s = "Hello world and man";
	int i = 25;
	int t = 0; 
	long double f = 0.1234567890123456789;
	int x = -1948409568;

	ft_printf("%-#-#--24O\n", 12, -874);
	printf("%-#-#--24O\n", 12, -874);

	// ft_printf("%-#14.3O\n",12);
	// printf("%-#14.3O\n",12);
}

