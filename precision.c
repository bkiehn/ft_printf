/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 21:23:26 by dzboncak          #+#    #+#             */
/*   Updated: 2019/02/28 22:23:39 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


char	*str_precision(t_p_buf *p_str)
{
	char	*res;

	if (p_str->precision > ft_strlen(p_str->data.str))
		return ft_strdup(p_str->data.str);
	else
		return (ft_strsub(p_str->data.str,0,p_str->precision));
}

char	*dec_precision(t_p_buf *p_str)
{
	char	*res;
	int		len;
	int		prec;

	prec = p_str->precision;
	len = ft_strlen(p_str->f_str);
	if (prec > len)
		return (char_add(p_str->f_str,'0',prec - len));
	else
		return (ft_strdup(p_str->f_str));
}

char	*use_presicion(t_p_buf *p_str)
{
	char	*res;

	if (p_str->d_type == STR)
		res = str_precision(p_str);
	else if (p_str->d_type == DEC)
		res = dec_precision(p_str);
	return (res);
}