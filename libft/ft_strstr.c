/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:45:25 by dzboncak          #+#    #+#             */
/*   Updated: 2018/11/24 19:55:58 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *sub)
{
	int	i;
	int	str_i;
	int	sub_i;

	i = 0;
	if (sub[0] == '\0')
		return ((char*)str);
	while (str[i] != '\0')
	{
		str_i = i;
		sub_i = 0;
		while (str[str_i] == sub[sub_i] && sub[sub_i] != '\0')
		{
			str_i++;
			sub_i++;
		}
		if (sub[sub_i] == '\0' && sub_i > 0)
			return ((char*)str + i);
		i++;
	}
	return (NULL);
}
