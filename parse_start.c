/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:02:33 by dzboncak          #+#    #+#             */
/*   Updated: 2019/03/04 00:16:50 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_length(t_p_buf *tmp, char *start)
{
	if (tmp->d_type == CHAR || tmp->d_type == STR || tmp->d_type == PTR)
		return (tmp->d_length = NO_LEN);
	while(start != tmp->end_find)
	{
		if (*start == 'h' && *(start + 1) == 'h')
			return (tmp->d_length = hh);
		else if (*start == 'h')
			return (tmp->d_length = h);
		else if (*start == 'l' && *(start + 1) == 'l')
			return (tmp->d_length = ll);
		else if (*start == 'l')
			return (tmp->d_length = l);
		else if (*start == 'L')
			return (tmp->d_length = L);
		start++;
	}
	return (tmp->d_length = NO_LEN);
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
	else if (c == 'f')
		return (p_str->d_type = FLOAT);
	return (0);

}

void	parse_precision(t_p_buf *tmp, char *start)
{
	while (start != tmp->end_find)
	{
		if (*start == '.')
		{
			tmp->end_find = start;
			if(tmp->d_type != CHAR)
				tmp->precision = ft_atoi(start + 1);
			return ;
		}
		start++;
	}
	tmp->precision = -1;
}

char*	get_format_str(t_p_buf *p_str)
{
	char	*str;

	if (p_str->d_type >= 4 && p_str->d_type <= 8)
		numeric_u(p_str);
	else if (p_str->d_type == DEC)
		numeric(p_str);
	else if (p_str->d_type == STR)
		p_str->f_str = ft_strdup(p_str->data.str);
	else if (p_str->d_type == CHAR)
		p_str->f_str = get_char(p_str->data.c);
	str = check_presicion(p_str);
	// printf("after prec:%s\n",str);
	str = check_width(p_str, str);
	// printf("after width:%s\n",str);

	return (str);
}

int 	find_max(int a, int b, int c)
{
	if(a >= b)
	{
		if (a >= c)
			return (a);
		return (c);
	}
	else if (b >= a)
	{
		if (b >= c)
			return (b);
		return (c);
	}
	else if (c >= a)
	{
		if (c >= b)
			return (c);
		return (b);
	}
	return (a);
}

int		end_parse(char *fin_str, t_p_buf *p_str)
{
	int		i;
	int		max;

	max = find_max(ft_strlen(fin_str),p_str->precision, p_str->width);
	i = 0;
	if (p_str->d_type != STR)
		while (i < max)
		{
			ft_putchar(fin_str[i]);
			i++;
		}
	else
		ft_putstr(fin_str);
	
	return (max);
}

int		parse_start(char **start, va_list *ap)
{
	t_p_buf p_str;
	char	*fin_str;
	char	*end_of_param;

	end_of_param = find_type(&p_str, *start, ap);
	parse_length(&p_str, *start);
	parse_precision(&p_str, *start);
	parse_width(&p_str, *start);
	parse_flags(&p_str, *start);
	fin_str = get_format_str(&p_str);

	*start = end_of_param;
	return (end_parse(fin_str, &p_str));
}