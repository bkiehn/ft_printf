#include "ft_printf.h"
#include <stdio.h>
#include <math.h>

int main()
{
	char *s = "Hello world and man";
	int i = 25;
	int i2 = 2512521;
	double f = 5.9999999999;

	ft_printf("%f\n", f);
	printf("%f\n", f);
}