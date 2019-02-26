/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:30:45 by dzboncak          #+#    #+#             */
/*   Updated: 2018/12/01 21:21:25 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		len;
	char	*res;
	int		i;

	len = ft_strlen(str);
	res = (char*)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while ((res[i] = str[i]) != '\0')
		i++;
	return (res);
}
