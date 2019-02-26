/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 21:52:39 by dzboncak          #+#    #+#             */
/*   Updated: 2018/11/30 18:58:50 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*res;

	res = (char*)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	bzero(res, size + 1);
	return (res);
}
