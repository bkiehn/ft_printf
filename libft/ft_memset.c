/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:48:22 by dzboncak          #+#    #+#             */
/*   Updated: 2018/12/03 21:20:33 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*temp;
	unsigned char	ch;

	i = 0;
	ch = (unsigned char)c;
	temp = (unsigned char*)b;
	while (i < len)
	{
		temp[i] = c;
		i++;
	}
	return (b);
}
