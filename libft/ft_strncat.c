/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:10:14 by dzboncak          #+#    #+#             */
/*   Updated: 2018/11/24 19:44:51 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(dst);
	i = 0;
	while ((i < n) && (src[i] != '\0'))
	{
		dst[i + len] = src[i];
		i++;
	}
	dst[i + len] = '\0';
	return (dst);
}
