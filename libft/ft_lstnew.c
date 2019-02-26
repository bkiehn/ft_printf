/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:05:28 by dzboncak          #+#    #+#             */
/*   Updated: 2018/11/29 23:18:24 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_list;
	void	*new_cont;

	new_list = (t_list*)malloc(sizeof(t_list));
	if (new_list == NULL)
		return (NULL);
	if (content == NULL)
	{
		new_list->content = NULL;
		new_list->content_size = 0;
	}
	else
	{
		new_cont = malloc(content_size);
		new_cont = ft_memcpy(new_cont, content, content_size);
		new_list->content = new_cont;
		new_list->content_size = content_size;
	}
	new_list->next = NULL;
	return (new_list);
}
