/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 17:27:31 by dzboncak          #+#    #+#             */
/*   Updated: 2019/03/01 19:57:19 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*dec_flags(t_p_buf *p_str, char *prev_str)
{
	
}

char	*use_flags(t_p_buf *p_str, char *prev_str)
{
	if (p_str->d_type == STR)
		return (prev_str);
	else if (p_str->d_type == DEC)
		return (dec_flags(p_str, prev_str));
	// else if (p_str->d_type >= PTR && p_str->d_type <= HEX_B)
	// 	return (hex_oct_flags(p_str,prec_s));
	
}

char	*use_width(t_p_buf *p_str, char *prec_s)
{
	int		res_len;

	res_len = p_str->width - ft_strlen(prec_s);
	if (res_len <= 0)
		return (prec_s);
	else
	{
		if (p_str->d_type == STR)
		return (char_add(prec_s,' ',res_len));
	}
	return (NULL);
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
	{
		tmp = use_width(p_str, prec_s);
		return (tmp);
	}
	else
	{
		tmp = use_flags_and_width(p_str, prec_s);
		return (tmp);
	}
}