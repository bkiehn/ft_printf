/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:42:30 by dzboncak          #+#    #+#             */
/*   Updated: 2018/12/10 15:29:58 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	if (n == 0)
		return ;
	i = 0;
	temp = (unsigned char*)s;
	while (i < n)
	{
		temp[i] = 0;
		i++;
	}
}
