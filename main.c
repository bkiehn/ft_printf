#include "ft_printf.h"
#include <stdio.h>
#include <math.h>

int main()
{
	char *s = "Hello world and man";
	int i = 25;
	int i2 = 2512521;
	long double f = 5.123456789;

	ft_printf("%.9Lf\n", f);
	printf("%.9Lf\n", f);
}