/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:02:33 by dzboncak          #+#    #+#             */
/*   Updated: 2019/03/01 19:28:38 by bkiehn           ###   ########.fr       */
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
	{
		p_str->f_str = ft_strdup(p_str->data.str);
		printf("ft_printf_str: %s\n", p_str->f_str);
	}
	else if (p_str->d_type == CHAR)
	{
		p_str->f_str = get_char(p_str->data.c);
		printf("ft_printf_char: %s\n", p_str->f_str);
	}
	

	
	

	return (str);
}

void	parse_start(t_str *tmp, char **start, va_list *ap)
{
	t_p_buf p_str;
	char	*fin_str;
	char	*end_of_param;

	if(*(*start + 1) == '%')
	{
		add_to_buf(tmp, '%');
		*start += 1;
		return ;
	}
	end_of_param = find_type(&p_str, *start, ap);
	//*start += 1;
	parse_length(&p_str, *start);
	parse_precision(&p_str, *start);
	parse_width(&p_str, *start);
	parse_flags(&p_str, *start);
	fin_str = get_format_str(&p_str);
	// ft_rejoin(tmp, fin_str);
	// ft_strdel(&fin_str);

	// printf("d_type = %d\nd_length = %d\nprecision = %d\nwidth = %d\n",
	// p_str.d_type, p_str.d_length, p_str.precision, p_str.width);
	// int i = 6;
	// while (i--)
	// 	printf("flag №%d = %d\n", i, p_str.flag[i]);

	// printf("\n");	
	
	*start = end_of_param;
}