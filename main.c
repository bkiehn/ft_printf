#include "ft_printf.h"
#include <stdio.h>
#include <math.h>
#include <limits.h>


int main()
{
	char *s = "Hello world and man";
	int i = 25;
	int i2 = 2512521;
	long double f = 5.123453236789;

	printf("*%d*\n",ft_printf("%+048.40lli", -1018186153));
	printf("*%d*\n",printf("%+048.40lli", -1018186153));
}
