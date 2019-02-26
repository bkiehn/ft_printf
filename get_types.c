/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_types.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 20:51:47 by dzboncak          #+#    #+#             */
/*   Updated: 2019/02/22 20:52:14 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_type(t_p_buf *p_str, va_list *ap)
{
	if (p_str->d_type == DEC || p_str->d_type == OCT || p_str->d_type == HEX
	|| p_str->d_type == HEX_B)
		p_str->data.i = (int)va_arg(*ap,int);
	else if (p_str->d_type == STR)
		p_str->data.str = va_arg(*ap,char*);
	else if (p_str->d_type == CHAR)
		p_str->data.c = (unsigned char)va_arg(*ap, int);
	else if (p_str->d_type == U_DEC)
		p_str->data.u_i = (unsigned int)va_arg(*ap, unsigned int);
}

char*	find_type(t_p_buf *p_str,char *s, va_list *ap)
{
	while(!type_char(*s,p_str))
	{
		s++;
	}
	write_type(p_str, ap);
	return (s);
}
