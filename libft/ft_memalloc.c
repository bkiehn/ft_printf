/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 21:15:32 by dzboncak          #+#    #+#             */
/*   Updated: 2018/11/25 21:31:31 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*res;
	size_t	i;

	res = (char*)malloc(size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < size)
	{
		res[i] = 0;
		i++;
	}
	return ((void*)res);
}
