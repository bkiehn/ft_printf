/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:00:26 by dzboncak          #+#    #+#             */
/*   Updated: 2019/02/26 17:29:08 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include <stdlib.h>

#define INIT_LEN 1
#define TO_ADD 10

void	init_vars(t_str *s)
{
	s->buf = ft_strnew(INIT_LEN);
	s->len = INIT_LEN;
}

void	ft_realloc(t_str *str)
{
	char *tmp;

	tmp = str->buf;
	str->len += TO_ADD;
	str->buf = ft_strnew(str->len);
	ft_strcpy(str->buf, tmp);
	ft_strdel(&tmp);
}

void	add_to_buf(t_str *tmp, char c)
{
	char	*to_del;
	int		char_count;

	char_count = ft_strlen(tmp->buf);
	if (char_count >= tmp->len)
		ft_realloc(tmp);
	tmp->buf[char_count] = c;
}

void	end_printf(t_str *tmp, va_list *ap)
{
	tmp->len = ft_strlen(tmp->buf);
	write(1, tmp->buf, tmp->len);
	ft_strdel(&tmp->buf);
	va_end(*ap);
}
int		ft_printf(const char * f, ...)
{
	va_list ap;
	t_str	tmp;

	va_start(ap, f);
	init_vars(&tmp);
	while (*f != '\0')
	{
		if(*f == '%')
		{
			parse_start(&tmp, (char**)&f, &ap);
		}
		else
		{
			add_to_buf(&tmp, *f);
		}
		f++;
	}
	end_printf(&tmp, &ap);
	return (tmp.len);
}