/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:12:19 by dzboncak          #+#    #+#             */
/*   Updated: 2019/03/03 23:04:50 by dzboncak         ###   ########.fr       */
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

void	parse_width(t_p_buf *tmp, char *start)
{
	while (start != tmp->end_find)
	{
		if (ft_isdigit(*start))
		{
			if (*start != '0')
			{
				tmp->end_find = start;
				tmp->width = ft_atoi(start);
				return ;
			}
		}
		start++;
	}
	if (tmp->d_type == CHAR)
		tmp->width = 1;
	else 
		tmp->width = -1;
}

void	parse_flags(t_p_buf *tmp, char *start)
{
	int		i;

	i = 6;
	while (i--)
		tmp->flag[i] = 0;
	while (start != tmp->end_find)
	{
		if (*start == '#' && tmp->flag[SHARP] == 0)
			tmp->flag[SHARP] = 1;
		else if (*start == '0' && tmp->flag[NOLL] == 0)
			tmp->flag[NOLL] = 1;
		else if (*start == '-' && tmp->flag[MINUS] == 0)
			tmp->flag[MINUS] = 1;
		else if (*start == '+' && tmp->flag[PLUS] == 0)
			tmp->flag[PLUS] = 1;
		else if (*start == ' ' && tmp->flag[SPACE] == 0)
			tmp->flag[SPACE] = 1;
		start++;
	}
	i = 6;
	while (i--)
		if (tmp->flag[i] == 1)
			return ;
	tmp->flag[NO_FLAG] = 1;
}