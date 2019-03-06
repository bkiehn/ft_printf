/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 21:23:26 by dzboncak          #+#    #+#             */
/*   Updated: 2019/03/06 23:26:41 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_precision(t_p_buf *p_str)
{
	if ((size_t)p_str->precision > ft_strlen(p_str->data.str))
		return (ft_strdup(p_str->f_str));
	else
		return (ft_strsub(p_str->f_str, 0, p_str->precision));
}

char	*sig_prec(t_p_buf *p_str,char *str, char c, int count, char sign)
{
	char	*start_ptr;
	int		len;
	int		prec;

	len = ft_strlen(p_str->f_str);
	prec = p_str->precision;
	start_ptr = str;
	start_ptr = ft_strsub(p_str->f_str, 1, len - 1);
	start_ptr = char_add(start_ptr, c, count + 1);
	start_ptr = char_add(start_ptr, sign, 1);
	return (start_ptr);
}

char	*dec_precision(t_p_buf *p_str)
{
	int		len;
	int		prec;
	char	*temp;

	prec = p_str->precision;
	len = ft_strlen(p_str->f_str);
	len = (p_str->f_str[0] != '-') ? len : len - 1;
	if (p_str->data.i == 0 && p_str->precision == 0)
		return (ft_strdup("\0"));
	if (prec > len)
	{
		if (p_str->f_str[0] != '-')
		{
			temp = ft_strdup(p_str->f_str);
			temp = char_add(temp, '0', prec - len);
		}
		else
			temp = sig_prec(p_str, p_str->f_str, '0', p_str->precision - ft_strlen(p_str->f_str), '-');
		return (temp);
	}
	else
		return (ft_strdup(p_str->f_str));
}

char	*ptr_precision(t_p_buf *p_str)
{
	if (!p_str->flag[SHARP] || p_str->flag[NO_FLAG])
	{
		p_str->flag[SHARP] = 1;
		p_str->flag[NO_FLAG] = 0;
	}
	p_str->d_type = HEX;
	if (p_str->data.i == 0 && p_str->precision == -1)
		p_str->flag[EXC] = 1;
	return (dec_precision(p_str));
}


char	*check_presicion(t_p_buf *p_str)
{
	if (p_str->flag[SHARP] &&
		(p_str->d_type >= DEC && p_str->d_type <= HEX_B) &&
		p_str->data.i == 0 && (p_str->precision == 0 || p_str->precision == -1))
	{
		if ((p_str->d_type != HEX && p_str->d_type != HEX_B))
			return (ft_strdup("0"));
		else if ((p_str->d_type == HEX || p_str->d_type == HEX_B)
		&& p_str->precision == -1)
			return (ft_strdup("0"));
		else
		{
			if ((p_str->d_type >= OCT && p_str->d_type <= HEX_B))
				p_str->flag[SHARP] = 0;
			return (ft_strdup("\0"));
		}
	}
	if (p_str->d_type == STR)
		return (str_precision(p_str));
	else if (p_str->d_type == DEC ||
	(p_str->d_type >= U_DEC && p_str->d_type <= HEX_B))
		return (dec_precision(p_str));
	else if (p_str->d_type == CHAR)
		return (p_str->f_str);
	else if (p_str->d_type == PTR)
		return (ptr_precision(p_str));
	return (p_str->f_str);
}
