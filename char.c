/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 23:09:42 by bkiehn            #+#    #+#             */
/*   Updated: 2019/02/28 23:49:59 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_char(char c)
{
	char	*res;

	res = ft_strnew(1);
	res[0] = c;
	printf("char:%s",res);
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

char	*char_add(char *str, char c, int n)
{
	char	*tmp;

	tmp = ft_strnew(ft_strlen(str) + n);
	ft_strcpy(tmp + n, str);
	ft_memset(tmp, c, n);
	free(str);
	return (tmp);
}