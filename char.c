/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 23:09:42 by bkiehn            #+#    #+#             */
/*   Updated: 2019/03/03 23:18:34 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_char(char c)
{
	char	*res;

	res = ft_strnew(1);
	res[0] = c;
	return (res);
}

char	*add_char(char *str, char c, int n)
{
	char	*tmp;

	tmp = ft_strnew(ft_strlen(str) + n);
	tmp = ft_strcpy(tmp, str);
	ft_memset(tmp + ft_strlen(str), c, n);
	free(str);
	return (tmp);
}

char	*add_char2zero(char *str, char c, int n, t_p_buf *p_str)
{
	char	*tmp;
	int		real_len;

	real_len = ft_strlen(str + 1) + 1;
	tmp = ft_strnew(real_len + n);
	tmp = ft_memcpy(tmp,str, real_len);
	ft_memset(tmp + real_len, c ,n);
	free(str);
	return (tmp);
}

char	*char_add(char *str, char c, int n)
{
	char	*tmp;


	tmp = ft_strnew(ft_strlen(str) + n);
	ft_strcpy(tmp + n, str);
	ft_memset(tmp, c, n);
	free(str);
	return (tmp);
}