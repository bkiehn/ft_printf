/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 21:10:42 by dzboncak          #+#    #+#             */
/*   Updated: 2018/12/03 21:20:45 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dst_tmp;
	const unsigned char	*src_tmp;
	size_t				i;

	i = 0;
	c = (unsigned char)c;
	dst_tmp = (unsigned char*)dst;
	src_tmp = (const unsigned char*)src;
	while (i < n)
	{
		dst_tmp[i] = src_tmp[i];
		if (src_tmp[i] == c)
		{
			return ((void*)(dst_tmp + (i + 1)));
		}
		i++;
	}
	return (NULL);
}
