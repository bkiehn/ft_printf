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
	char *t;

	t = (char*)malloc(sizeof(char) * 4);
	ft_printf("%10.3s", s);
	//printf("%c dewd", '\0');
}