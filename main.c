#include "ft_printf.h"
#include <stdio.h>


void	test(int n, ...)
{
	va_list ap;
	char *res;


	va_start(ap,n);
	char c;
	c = (unsigned char)va_arg(ap, int);
	res = ft_strnew(2);
	res[0] = c;
	printf("got %s",res);
}

int main()
{
	//ft_printf("%10c Hello man\n",'z');

	int d = -1000;
	char *s = "Hello";
	double f = -50.45916;
	printf("");

}