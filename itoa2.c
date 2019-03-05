/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 23:24:55 by bkiehn            #+#    #+#             */
/*   Updated: 2019/03/05 21:34:35 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*itoa_oct(unsigned long long int i)
{
	char					*str;
	unsigned long long int	tmp;
	unsigned long long int	ost;

	str = ft_strnew(1);
	ost = i;
	while(ost > 7)
	{
		tmp = ost;
		ost = tmp / 8;
		i = tmp - (ost * 8);
		str = char_add(str, i % 10 + '0', 1);
	}
	str = char_add(str, ost % 10 + '0', 1);
	return (str);
}

long double			ft_pow(long long x, int y)
{
	long double z;
	int		f;
	
	f = 0;
	if (y == 0)
		return (1);
	else if (y < 0)
	{
		y = abs(y);
		f = 1;
	}
	z = x;
	while (--y)
	{
		z = z * x;
	}
	if (f == 1)
		return (1 / z);
	return (z);
}

char				*ft_itoa_double(long double i, int prec)
{
	char			*str;
	long long		real;
	t_flag_f		f[7];
	int				j;
	
	j = 7;
	while (j--)
		f[j] = 0;
	if ((real = i) < 0)
	{
		f[neg] = 1;
		real = -real;
		i = -i;
	}
	if (prec == -1)
		prec = 6;
	str = d_to_s(i, f, prec, real);
	return (str);
}