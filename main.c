#include "ft_printf.h"
#include <stdio.h>
#include <math.h>

int main()
{
	char *s = "Hello world and man";
	int d = 25;
	int f = 2512521;

	ft_printf("%10.5D\n",f);
	printf("%10.5D\n",f);
}