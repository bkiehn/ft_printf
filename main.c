#include "ft_printf.h"

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
	int d = 1000;
	char *s = "Hello";
	double f = -50.45916;

	ft_printf("%lld", 32147483647);
	printf("printf: %d\n", 10);
}