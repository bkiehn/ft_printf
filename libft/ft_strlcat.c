/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 20:35:21 by dzboncak          #+#    #+#             */
/*   Updated: 2018/12/03 21:22:02 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_min(size_t n1, size_t n2)
{
	if (n1 <= n2)
		return (n1);
	else
		return (n2);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		dst_len;
	size_t		i;
	size_t		res;

	dst_len = ft_strlen(dst);
	res = ft_strlen(src);
	i = 0;
	while ((i + dst_len + 1) < size && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	res += ft_min(dst_len, size);
	return (res);
}
