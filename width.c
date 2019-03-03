/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 17:27:31 by dzboncak          #+#    #+#             */
/*   Updated: 2019/03/03 18:47:41 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*dec_flags(t_p_buf *p_str, char *prev_str)
{
	char	*tmp;

	tmp = prev_str;
	if (p_str->f_str[0] != '-' && p_str->flag[PLUS] && p_str->d_type != U_DEC)
		return (tmp = char_add(tmp,'+', 1));
	else if (p_str->f_str[0] != '-' && !p_str->flag[MINUS] && p_str->flag[SPACE] && p_str->d_type != U_DEC)
		return (tmp = char_add(tmp,' ', 1));
	else if (p_str->precision == -1 && p_str->flag[NOLL] && !p_str->flag[MINUS] && p_str->d_type != U_DEC)
	{
		if(p_str->f_str[0] == '-')
		{
			tmp = neg_prec(p_str,tmp,'0',p_str->width - ft_strlen(prev_str));
			ft_strdel(&prev_str);
		}
		else
		{
			tmp  = char_add(tmp, '0', p_str->width - ft_strlen(prev_str));
		}
	}
	return (tmp);
}

char	*hex_oct_flags(t_p_buf *p_str, char *prev_str)
{
	char	*tmp;
	int		diff;

	tmp = prev_str;
	diff = ft_strlen(prev_str) - p_str->precision;
	if (p_str->flag[SHARP] && p_str->flag[NOLL] && !p_str->flag[MINUS] && p_str->precision == -1)
	{
			tmp  = char_add(tmp, '0', p_str->width - ft_strlen(prev_str) - 2);
	}
	if(p_str->d_type == HEX && p_str->flag[SHARP] && diff >= 0 )
	{
		tmp = char_add(tmp,'x', 1);
		tmp = char_add(tmp,'0',1);
	}
	else if(p_str->d_type == HEX_B && p_str->flag[SHARP] && diff >= 0)
	{
		tmp = char_add(tmp,'X', 1);
		tmp = char_add(tmp,'0',1);
	}
	else if(p_str->d_type == OCT && p_str->flag[SHARP] && diff >= 0)
	{
		tmp = char_add(tmp,'0',1);
	}
	
	return (tmp);
}

char	*use_flags(t_p_buf *p_str, char *prev_str)
{
	if (p_str->d_type == STR || p_str->d_type == CHAR)
		return (prev_str);
	else if (p_str->d_type == DEC || p_str->d_type == U_DEC)
		return (dec_flags(p_str, prev_str));
	else if (p_str->d_type >= OCT && p_str->d_type <= HEX_B)
		return (hex_oct_flags(p_str,prev_str));
}

char	*use_width(t_p_buf *p_str, char *prev_s)
{
	int		to_add;
	char	*tmp;

	to_add = p_str->width - ft_strlen(prev_s);
	tmp = prev_s;
	if (to_add <= 0)
		return (prev_s);
	else
	{
		if(p_str->flag[MINUS])
			return (add_char(tmp, ' ',to_add));
		return (char_add(tmp, ' ',to_add));
	}
	return (tmp);
}


char	*use_flags_and_width(t_p_buf *p_str, char *prec_s)
{
	char	*tmp;
	int		res_len;

	tmp = prec_s;
	tmp = use_flags(p_str, tmp);
	tmp = use_width(p_str, tmp);

	return (tmp);
}

char	*check_width(t_p_buf *p_str, char *prec_s)
{
	char	*tmp;

	if(p_str->flag[0])
		tmp = use_width(p_str, prec_s);
	else
		tmp = use_flags_and_width(p_str, prec_s);
	return (tmp);
}