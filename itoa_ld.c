/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_ld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 22:46:43 by bkiehn            #+#    #+#             */
/*   Updated: 2019/03/05 23:31:14 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_itoa_ldouble(long double i, int prec)//тестовая фукция, нигде не используется
{
	long long	real;
	long long	tmpreal;
	char		*str;

	real = i;
	str = ft_strnew(1);
	if (prec == -1)
		prec = 6;
	prec += 2;
	while (prec--)
	{
		str = add_char(str, (i * 10 - real * 10) + '0', 1);
		i = (i - (long double)real) * 10;
		real = i;
	}
	return (str);
}
