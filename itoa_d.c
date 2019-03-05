/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:24:37 by bkiehn            #+#    #+#             */
/*   Updated: 2019/03/05 22:28:29 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*d_to_s(long double i, t_flag_f *f, int prec, long long real)
{
	char	*str2;
	char	*str;
	char	discharge;
	int		lstr;

	str = ft_itoa(i);
	lstr = ft_strlen(str) - 1;
	f[lc] = str[lstr];
	if (prec != 0)
	{
		str2 = flags_f(f, i, prec, real);
		str2 = drob_f(str2, prec, f, i);
	}
	else
		flags_f_p0(f, i, prec, real);
	//printf("p2 = %d p1r = %d p1b = %d po = %d dis = %d p0p = %c\n", f[p2], f[p1r], f[p1b], f[p0], f[dis], f[lc]);
	str = real_f(f, str, lstr);
	if (f[neg] == 1)
		str = char_add(str, '-', 1);
	if (prec != 0)
		str = ft_strjoin(str, str2);
	return (str);
}

char			*real_f(t_flag_f *f, char *str, int lstr)
{
	while (f[dis] == 1)
	{
		f[dis] = 0;
		str[lstr]++;
		if (str[lstr] > '9')
		{
			str[lstr] = '0';
			f[dis] = 1;
		}
		lstr--;
		if (lstr < 0 && f[dis] == 1)
		{
			f[dis] = 0;
			str = char_add(str, '1', 1);
		}
	}
	return (str);
}

char			*flags_f(t_flag_f *f, long double i, int p, long long r)
{
	char	*str2;
	char	d;

	str2 = ft_strnew(1);
	if ((int)(i * ft_pow(10, p + 2) - r * ft_pow(10, p + 2)) % 10 + '0' == '0')
		i = i + ft_pow(10, -(p + 3));
	if ((int)(i * ft_pow(10, p + 2) - r * ft_pow(10, p + 2)) % 10 + '0' > '0')
		f[p2] = 1;
	if ((int)(i * ft_pow(10, p + 1) - r * ft_pow(10, p + 1)) % 10 + '0' == '5')
		f[p1r] = 1;
	if ((int)(i * ft_pow(10, p + 1) - r * ft_pow(10, p + 1)) % 10 + '0' > '5')
		f[p1b] = 1;
	if ((d = (int)(i * ft_pow(10, p) - r * ft_pow(10, p)) % 10 + '0') > '6')
		f[p0] = 1;
	if (f[p1b] == 1)
		d++;
	else if ((f[p1r] == 1 && f[p2] == 1) || (f[p0] == 1 && f[p1r] == 1))
		d++;
	if (d > '9')
	{
		d = '0';
		f[dis] = 1;
	}
	return (char_add(str2, d, 1));
}

char			*drob_f(char *str2, int prec, t_flag_f *f, long double i)
{
	long long	real;
	char		d;

	real = i;
	while (--prec)
	{
		d = (int)(i * ft_pow(10, prec) - real * ft_pow(10, prec)) % 10 + '0';
		if (f[dis] == 1)
		{
			d++;
			f[dis] = 0;
		}
		if (d > '9')
		{
			d = '0';
			f[dis] = 1;
		}
		str2 = char_add(str2, d, 1);
	}
	str2 = char_add(str2, '.', 1);
	return (str2);
}

void			flags_f_p0(t_flag_f *f, long double i, int p, long long r)
{
	char	discharge;

	discharge = f[lc];
	if ((int)(i * ft_pow(10, p + 2) - r * ft_pow(10, p + 2)) % 10 + '0' == '0')
		i = i + ft_pow(10, -(p + 3));
	if ((int)(i * ft_pow(10, p + 2) - r * ft_pow(10, p + 2)) % 10 + '0' > '0')
		f[p2] = 1;
	if ((int)(i * ft_pow(10, p + 1) - r * ft_pow(10, p + 1)) % 10 + '0' == '5')
		f[p1r] = 1;
	if ((int)(i * ft_pow(10, p + 1) - r * ft_pow(10, p + 1)) % 10 + '0' > '5')
		f[p1b] = 1;
	if (discharge > '4')
		f[p0] = 1;
	if ((f[p1b] == 1) || (f[p1r] == 1 && (discharge % 2) != 0)
	|| (f[p2] == 1 && f[p1r] == 1))
		f[dis] = 1;
}
