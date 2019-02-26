/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:04:42 by dzboncak          #+#    #+#             */
/*   Updated: 2018/12/10 15:29:41 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	char			ch;

	i = 0;
	ch = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			return ((char*)(s + i));
		i++;
	}
	if (c == '\0' && s[i] == '\0')
		return ((char*)(s + i));
	return (NULL);
}
