/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 13:00:07 by jfazakas          #+#    #+#             */
/*   Updated: 2015/10/31 17:29:06 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinsert(t_list **lst, t_list *new, int (*cmp)(t_list *, t_list *))
{
	t_list	*node;
	t_list	*prev;

	node = *lst;
	prev = NULL;
	while (node != NULL && (*cmp)(new, node) > 0)
	{
		prev = node;
		node = node->next;
	}
	if (prev == NULL)
		ft_lstadd(lst, new);
	else
	{
		prev->next = new;
		new->next = node;
	}
}
