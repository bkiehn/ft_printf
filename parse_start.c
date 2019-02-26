/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:02:33 by dzboncak          #+#    #+#             */
/*   Updated: 2019/02/26 16:06:18 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flags(t_p_buf *tmp, char **start)
{
	
}

void	parse_width(t_p_buf *tmp, char **start)
{
	printf("pointing to %c",**start);
	tmp->len = ft_atoi(*start);
	
	return ;
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

void	parse_precision(t_p_buf *tmp, char **start)
{
	return ;
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
	char	*res;
	char	*tmp;

	res = ft_strnew(p_str->len);
	
	return (res);
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
	*start += 1;
	//parse_flags(&p_str, start);
	parse_width(&p_str, start);
	//parse_precision(tmp, start, ap);
	// parse_length(tmp, start, ap);
	fin_str = get_format_str(&p_str);
	ft_rejoin(tmp, fin_str);
	ft_strdel(&fin_str);
	*start = end_of_param;
}