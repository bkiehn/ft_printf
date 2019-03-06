#include "ft_printf.h"
#include <stdio.h>
#include <math.h>
#include <limits.h>


int main()
{
	char *s = "Hello world and man";
	int i = 25;
	int i2 = 2512521;
	long double f = 0.1234567890123456789;

	printf("*%d*\n",ft_printf("%Lf", f));
	printf("*%d*\n",printf("%Lf", f));
}
