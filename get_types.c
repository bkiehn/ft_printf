/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_types.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 20:51:47 by dzboncak          #+#    #+#             */
/*   Updated: 2019/02/26 22:20:08 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_dec(t_p_buf *p_str, va_list *ap)
{
	if (p_str->d_type == DEC)
	{
		if (p_str->d_length == hh)
			p_str->data.c = (char)va_arg(*ap, int);
		else if (p_str->d_length == h)
			p_str->data.s = (short)va_arg(*ap, int);
		else if (p_str->d_length == l)
			p_str->data.l = (long)va_arg(*ap, long);
		else if (p_str->d_length == ll)
			p_str->data.ll = (long long)va_arg(*ap, long long);
		else if (p_str->d_length == NO_LEN)
			p_str->data.i = (int)va_arg(*ap, int);
	}
	else if (p_str->d_type == U_DEC || p_str->d_type == OCT ||
	p_str->d_type == HEX || p_str->d_type == HEX_B)
	{
		if (p_str->d_length == hh)
			p_str->data.u_c = (unsigned char)va_arg(*ap,unsigned int);
		else if (p_str->d_length == h)
			p_str->data.u_s = (unsigned short)va_arg(*ap,unsigned int);
		else if (p_str->d_length == l)
			p_str->data.u_l = (unsigned long)va_arg(*ap,unsigned long);
		else if (p_str->d_length == ll)
			p_str->data.u_ll = (unsigned long long)va_arg(*ap,unsigned long long);
		else if (p_str->d_length == NO_LEN)
			p_str->data.i = (unsigned int)va_arg(*ap,unsigned int);
	}
	else if (p_str->d_type == CHAR)
		p_str->data.c = (char)va_arg(*ap, int);
}

void	write_type(t_p_buf *p_str, va_list *ap)
{
	if ((p_str->d_type >= DEC && p_str->d_type <= HEX_B) || p_str->d_type == CHAR)
		write_dec(p_str, ap);
	else if (p_str->d_type == STR)
		p_str->data.str = (char *)va_arg(*ap, char *);
	else if (p_str->d_type == PTR)
		p_str->data.pointer = (size_t) va_arg(*ap, size_t);
	else if (p_str->d_type == FLOAT)
		{
			if (p_str->d_length == l || p_str->d_length == NO_LEN)
				p_str->data.dbl = va_arg(*ap, double);
			else if (p_str->d_length == L)
				p_str->data.l_dbl = (long double)va_arg(*ap, long double);
		}
}

int		type_char(char c, t_p_buf *p_str)
{
	if (c == 'd' || c == 'i')
		return (p_str->d_type = DEC);
	else if (c == 's')
		return (p_str->d_type = STR);
	else if (c == 'p')
		return (p_str->d_type = PTR);
	else if (c == 'c')
		return (p_str->d_type = CHAR);
	else if (c == 'o')
		return (p_str->d_type = OCT);
	else if (c == 'u')
		return (p_str->d_type = U_DEC);
	else if (c == 'x')
		return (p_str->d_type = HEX);
	else if (c == 'X')
		return (p_str->d_type = HEX_B);
	return (0);

}

int		len_char(char *s, t_p_buf *p_str)
{
	if (*s == 'h')
	{
		if (*(s + 1) == 'h')
			return (p_str->d_length = hh);
		else
			return (p_str->d_length = h);
	}
	else if (*s == 'l')
	{
		if (*(s + 1) == 'l')
			return (p_str->d_length = ll);
		else
			return (p_str->d_length = l);
	}
	else if (*s == 'L')
		return (p_str->d_length = L);
	return (NO_LEN);
}

void	parse_length(t_p_buf *p_str, char *s, char *end)
{
	if (p_str->d_type == CHAR || p_str->d_type == STR || p_str->d_type == PTR)
	{
		p_str->d_length = NO_LEN;
		return ;
	}
	while(!len_char(s,p_str) && s != end)
		s++;
}

char*	find_type(t_p_buf *p_str,char *s, va_list *ap)
{
	char *to_start;

	to_start = s;
	while(!type_char(*s,p_str))
	{
		s++;
	}
	parse_length(p_str, to_start, s);
	write_type(p_str, ap);
	return (s);
}
