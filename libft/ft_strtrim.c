/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:17:18 by dzboncak          #+#    #+#             */
/*   Updated: 2018/11/28 22:23:22 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	char	*res;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) == 0)
		return (ft_strnew(1));
	start = 0;
	while (ft_isspace(s[start]))
	{
		start++;
	}
	end = ft_strlen(s) - 1;
	while (ft_isspace(s[end]) && end > start)
	{
		end--;
	}
	res = ft_strsub(s, start, end - start + 1);
	if (res == NULL)
		return (NULL);
	return (res);
}
