/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:02:33 by dzboncak          #+#    #+#             */
/*   Updated: 2019/02/26 23:03:14 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_flag(char c, t_p_buf *tmp)
{
	if (c == '+')
		return (tmp->f_plus = 1);
	else if (c == '-')
		return (tmp->f_minus = 1);
	else if (c == ' ')
		return (tmp->f_space = 1);
	else if (c == '#')
		return (tmp->f_hash = 1);
	else if (c == '0')
		return (tmp->f_zero = 1);
	return (0);
}

int		is_digit(char c)
{
	if (c >= '1' && c <= '9')
		return (1);
	return (0);
}

void	parse_flags(t_p_buf *tmp, char **s)
{
	while (is_flag(**s, tmp) && !is_digit(**s))
		(*s) += 1;
}

void	parse_width(t_p_buf *tmp, char **start)
{
	int		res;

	res = ft_atoi(*start);
	if (res == 0)
		return ;
	tmp->width = res;
}



void	parse_precision(t_p_buf *tmp, char **start, char *end)
{
	int		res;

	while(*start != end)
	{
		if(**start  == '.')
		{
			(*start) += 1;
			break ;	
		}
		(*start) += 1;
	}
	res = ft_atoi(*start);
	if (res != 0)
		tmp->precision = res;
}

char	*get_char(t_p_buf *p_str)
{
	char	*res;

	res = ft_strnew(2);
	res[0] = p_str->data.c;
	return (res);
}

char*	get_format_str(t_p_buf *p_str)
{
	char *res;
	if (p_str->d_type == DEC)
	{
		 res = ft_itoa(p_str->data.i);
	}
	else if (p_str->d_type == U_DEC)
		res = ft_itoa_u(p_str->data.u_i);
	else if (p_str->d_type == STR)
		res = ft_strdup(p_str->data.str);
	else if (p_str->d_type == CHAR)
		res = get_char(p_str);
	else if (p_str->d_type == PTR)
		res = ft_itoa(p_str->data.i);
	return (res);
}

void	parse_start(t_str *tmp, char **start, va_list *ap)
{
	t_p_buf p_str;
	char	*fin_str;
	char	*end;

	if(*(*start + 1) == '%')
	{
		add_to_buf(tmp, '%');
		*start += 1;
		return ;
	}
	init_p_str(&p_str);
	end = find_type(&p_str, *start, ap); // Get and write data to parse buf and save pointer to pointer
	*start += 1;
	parse_flags(&p_str, start);
	parse_width(&p_str, start);
	parse_precision(&p_str, start, end);
	fin_str = get_format_str(&p_str);
	ft_rejoin(tmp, fin_str);     //Add formated string to the output buf
	ft_strdel(&fin_str);
	*start = end;
}