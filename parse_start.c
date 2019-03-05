/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:02:33 by dzboncak          #+#    #+#             */
/*   Updated: 2019/03/05 22:06:58 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_length(t_p_buf *tmp, char *start)
{
	if (tmp->d_type == CHAR || tmp->d_type == STR || tmp->d_type == PTR)
		return (tmp->d_length = NO_LEN);
	while (start != tmp->end_find)
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

void	parse_precision(t_p_buf *tmp, char *start)
{
	while (start != tmp->end_find)
	{
		if (*start == '.')
		{
			tmp->end_find = start;
			if (tmp->d_type != CHAR)
				tmp->precision = ft_atoi(start + 1);
			return ;
		}
		start++;
	}
	tmp->precision = -1;
}

char	*get_format_str(t_p_buf *p_str, va_list *ap)
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
	else if (p_str->d_type == FLOAT)
		numeric_f(p_str, ap);
	if (p_str->d_type != FLOAT)//из numeric_f str возвращается уже с точностью
		str = check_presicion(p_str);
	// printf("prec:%s\n",str);
	str = check_width(p_str, str);
		printf(":%s\n",str);
	return (str);
}
