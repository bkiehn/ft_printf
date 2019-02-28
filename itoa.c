/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 19:45:13 by bkiehn            #+#    #+#             */
/*   Updated: 2019/02/28 21:02:04 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int		minus(long long int n, long long int *i)
{
	if (n == -9223372036854775808)
	{
		*i += 2;
		return (-(n % 1000000000000000000));
	}
	else
		*i = *i + 1;
	return (-n);
}

char				*ft_itoa_long(long long int n)
{
	char			*a;
	long long int	i;
	long long int	buf;

	i = 2;
	if (n < 0)
		n = minus(n, &i);
	buf = n;
	while ((buf = (buf / 10)) > 0)
		i++;
	if (!(a = malloc(sizeof(char) * i)))
		return (0);
	a[--i] = '\0';
	a[--i] = (n % 10) + '0';
	while ((n = (n / 10)) > 0)
		a[--i] = (n % 10) + '0';
	if (i == 2)
		a[--i] = '9';
	if (i == 1)
		a[--i] = '-';
	return (a);
}

char				*ft_itoa_unlong(unsigned long long int n)
{
	char						*a;
	unsigned long long int		i;
	unsigned long long int		buf;

	i = 2;
	buf = n;
	while ((buf = (buf / 10)) > 0)
		i++;
	if (!(a = malloc(sizeof(char) * i)))
		return (0);
	a[--i] = '\0';
	a[--i] = (n % 10) + '0';
	while ((n = (n / 10)) > 0)
		a[--i] = (n % 10) + '0';
	return (a);
}

char				*itoa_hex(long long int i)
{
	return (0);
}