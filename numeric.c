/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 22:01:02 by bkiehn            #+#    #+#             */
/*   Updated: 2019/03/04 17:42:39 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		numeric_u(t_p_buf *p_str)
{
	unsigned long long int i;

	if (p_str->d_length == NO_LEN)
		i = (unsigned int)p_str->data.i;
	else if (p_str->d_length == hh)
		i = (unsigned char)p_str->data.i;
	else if (p_str->d_length == h)
		i = (unsigned short)p_str->data.i;
	else if (p_str->d_length == l)
		i = (unsigned long int)p_str->data.i;
	if (p_str->d_length == ll || p_str->d_type == PTR)
		i = (unsigned long long int)p_str->data.i;
	if (p_str->d_type == U_DEC)
		p_str->f_str = ft_itoa_unlong(i);
	else if (p_str->d_type == HEX || p_str->d_type == PTR)
		p_str->f_str = itoa_hex(i, 0);
	else if (p_str->d_type == HEX_B)
		p_str->f_str = itoa_hex(i, 1);
	else if (p_str->d_type == OCT)
		p_str->f_str = itoa_oct(i);
}

void		numeric(t_p_buf *p_str)
{
	if (p_str->d_length == NO_LEN)
		p_str->f_str = ft_itoa_long((int)p_str->data.i);
	else if (p_str->d_length == hh)
		p_str->f_str = ft_itoa_long((char)p_str->data.i);
	else if (p_str->d_length == h)
		p_str->f_str = ft_itoa_long((short)p_str->data.i);
	else if (p_str->d_length == l)
		p_str->f_str = ft_itoa_long((long int)p_str->data.i);
	else if (p_str->d_length == ll)
		p_str->f_str = ft_itoa_long((long long int)p_str->data.i);
}