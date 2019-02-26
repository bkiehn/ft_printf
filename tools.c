/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:12:19 by dzboncak          #+#    #+#             */
/*   Updated: 2019/02/26 23:03:25 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	ft_rejoin(t_str *tmp, char *str)
{
	char	*temp;
	size_t	char_count;
	

	char_count = ft_strlen(tmp->buf);
	char_count += ft_strlen(str);
	if (char_count >= tmp->len)
		ft_realloc(tmp);
	temp = tmp->buf;
	tmp->buf = ft_strjoin(temp, str);
	ft_strdel(&temp);
}

void	init_p_str(t_p_buf *p_str)
{
	p_str->f_hash = 0;
	p_str->f_minus = 0;
	p_str->f_plus = 0;
	p_str->f_space = 0;
	p_str->f_zero = 0;
	p_str->precision = -1;
	p_str->width = -1;
}

size_t	ft_calc_size_u(unsigned int n)
{
	size_t		len;

	len = 1;
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


char			*ft_itoa_u(unsigned int n)
{
	char		*res;
	size_t		len;
	size_t		i;

	len = ft_calc_size_u(n);
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
	res[i] = '\0';
	ft_strrev(res);
	return (res);
}