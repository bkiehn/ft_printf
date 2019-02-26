/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:21:31 by dzboncak          #+#    #+#             */
/*   Updated: 2018/12/10 15:28:45 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				last_occur;
	int				i;
	unsigned char	ch;

	i = 0;
	ch = (unsigned char)c;
	last_occur = -1;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == ch)
			last_occur = i;
		i++;
	}
	if (s[i] == '\0' && c == '\0')
	{
		return ((char*)s + i);
	}
	if (last_occur == -1)
		return (NULL);
	return ((char*)s + last_occur);
}
