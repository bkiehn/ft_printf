/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:20:07 by dzboncak          #+#    #+#             */
/*   Updated: 2019/02/19 18:27:40 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_calc_size(int n)
{
	size_t		len;

	len = 1;
	if (n < 0)
	{
		len += 1;
		n = -n;
	}
	while ((n = (n / 10)) > 0)
	{
		len++;
	}
	return (len);
}

static void		ft_strrev(char *str)
{
	size_t		len;
	size_t		i;
	char		c;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		c = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = c;
		i++;
	}
}


char			*ft_itoa(int n)
{
	char		*res;
	int			sign;
	size_t		len;
	size_t		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if ((sign = n) < 0)
		n = -n;
	len = ft_calc_size(n);
	res = (char*)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	if (sign < 0)
		res[i++] = '-';
	res[i] = '\0';
	ft_strrev(res);
	return (res);
}
