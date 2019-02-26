/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 22:16:13 by dzboncak          #+#    #+#             */
/*   Updated: 2018/11/26 20:50:01 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_tmp;
	unsigned char	*s2_tmp;

	s1_tmp = (unsigned char*)s1;
	s2_tmp = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (n-- && *s1_tmp == *s2_tmp)
	{
		if (n != 0)
		{
			s1_tmp++;
			s2_tmp++;
		}
	}
	return ((unsigned char)*s1_tmp - (unsigned char)*s2_tmp);
}
