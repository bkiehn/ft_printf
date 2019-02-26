/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:12:19 by dzboncak          #+#    #+#             */
/*   Updated: 2019/02/22 19:12:41 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_rejoin(t_str *tmp, char *str)
{
	char	*temp;
	size_t	char_count;
	
	char_count = ft_strlen(tmp->buf);
	char_count += ft_strlen(str);
	if (char_count >= tmp->len)
		ft_realloc(tmp);
	temp = tmp->buf;
	tmp->buf = ft_strjoin(tmp->buf, str);
	ft_strdel(&temp);
}