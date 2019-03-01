/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 23:24:55 by bkiehn            #+#    #+#             */
/*   Updated: 2019/03/01 18:31:19 by bkiehn           ###   ########.fr       */
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