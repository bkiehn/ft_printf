/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 21:23:26 by dzboncak          #+#    #+#             */
/*   Updated: 2019/03/01 23:17:44 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_precision(t_p_buf *p_str)
{
	char	*res;

	if (p_str->precision > ft_strlen(p_str->data.str))
		return (ft_strdup(p_str->data.str));
	else
		return (ft_strsub(p_str->data.str,0,p_str->precision));
}

char	*neg_prec(t_p_buf *p_str,char *str, char c, int count)
{
	char	*start_ptr;
	char	*temp;
	int		len;
	int		prec;

	len = ft_strlen(p_str->f_str);
	prec = p_str->precision;
	if (count < 0)
		printf("count < 0!");
	start_ptr = ft_strsub(p_str->f_str, 1, len - 1);
	start_ptr = char_add(start_ptr, c, count + 1);
	start_ptr = char_add(start_ptr, '-', 1);
	return (start_ptr);
}

char	*dec_precision(t_p_buf *p_str)
{
	char	*res;
	int		len;
	int		prec;
	char	*temp;

	prec = p_str->precision;
	len = ft_strlen(p_str->f_str);
	len = (p_str->f_str[0] != '-') ? len : len - 1;
	if (prec > len)
	{
		if (p_str->f_str[0] != '-')
		{
			temp = ft_strdup(p_str->f_str);
			temp = char_add(temp,'0',prec - len);
		}
		else
			temp = neg_prec(p_str,p_str->f_str, '0', p_str->precision - ft_strlen(p_str->f_str));
		return temp;
	}
	else
		return (ft_strdup(p_str->f_str));
}

char	*check_presicion(t_p_buf *p_str)
{
	char	*res;

	if (p_str->d_type == STR)
		res = str_precision(p_str);
	else if (p_str->d_type == DEC || (p_str->d_type >= U_DEC && p_str->d_type <= HEX_B))
		res = dec_precision(p_str);
	// else if (p_str->d_type == PTR)
	// 	res = ptr_precision(p_str);
	// else if (p_str->d_type == FLOAT)
	// 	res = float_precision(p_str);
	
	return (res);
}