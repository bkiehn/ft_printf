/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 22:02:06 by dzboncak          #+#    #+#             */
/*   Updated: 2018/11/26 20:50:22 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_tmp;
	size_t				i;

	i = 0;
	s_tmp = (const unsigned char*)s;
	c = (unsigned char)c;
	while (i < n)
	{
		if (s_tmp[i] == c)
			return ((void *)(s_tmp + i));
		i++;
	}
	return (NULL);
}
