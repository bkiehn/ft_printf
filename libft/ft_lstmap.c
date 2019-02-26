/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 22:11:44 by dzboncak          #+#    #+#             */
/*   Updated: 2018/11/29 23:19:00 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*current;

	if (lst == NULL || f == NULL)
		return (NULL);
	head = f(lst);
	lst = lst->next;
	current = head;
	while (lst)
	{
		current->next = f(lst);
		lst = lst->next;
		current = current->next;
	}
	return (head);
}
