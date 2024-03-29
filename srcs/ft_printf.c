/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:00:26 by dzboncak          #+#    #+#             */
/*   Updated: 2019/03/07 16:05:42 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		end_parse(char *fin_str, t_p_buf *p_str)
{
	int		i;
	int		max;

	if (p_str->d_type == STR)
		max = ft_strlen(fin_str);
	else
		max = find_max(ft_strlen(fin_str), p_str->precision, p_str->width);
	i = 0;
	if (p_str->d_type != STR)
		while (i < max)
		{
			ft_putchar(fin_str[i]);
			i++;
		}
	else
		ft_putstr(fin_str);
	ft_strdel(&fin_str);
	if (p_str->d_type == STR && ft_strequ(p_str->data.str, "(null)"))
	{
		ft_strdel(&p_str->data.str);
		ft_strdel(&p_str->f_str);
	}
	if (p_str->d_type != CHAR && p_str->d_type != FLOAT)
		ft_strdel(&p_str->f_str);
	return (max);
}

int		parse_start(char **start, va_list *ap)
{
	t_p_buf p_str;
	char	*fin_str;
	char	*end_of_param;

	*start += 1;
	p_str.d_length = NO_LEN;
	end_of_param = find_type(&p_str, *start, ap);
	parse_length(&p_str, *start);
	parse_precision(&p_str, *start);
	parse_width(&p_str, *start);
	parse_flags(&p_str, *start);
	fin_str = get_format_str(&p_str, ap);
	*start = end_of_param;
	return (end_parse(fin_str, &p_str));
}

int		ft_printf(const char *f, ...)
{
	va_list ap;
	int		res;

	va_start(ap, f);
	res = 0;
	while (*f != '\0')
	{
		if (*f == '%')
		{
			res += parse_start((char**)&f, &ap);
		}
		else
		{
			ft_putchar(*f);
			res += 1;
		}
		f++;
	}
	return (res);
}
