/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 21:49:24 by dzboncak          #+#    #+#             */
/*   Updated: 2018/11/26 20:51:25 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_tmp;
	const char	*src_tmp;
	size_t		i;

	i = 0;
	dst_tmp = (char*)dst;
	src_tmp = (char*)src;
	if (src < dst)
	{
		while (len--)
		{
			dst_tmp[len] = src_tmp[len];
		}
	}
	else
	{
		while (i < len)
		{
			dst_tmp[i] = src_tmp[i];
			i++;
		}
	}
	return (dst);
}
