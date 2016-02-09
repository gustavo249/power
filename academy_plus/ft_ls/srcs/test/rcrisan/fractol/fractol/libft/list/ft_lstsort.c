/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 13:09:43 by jfazakas          #+#    #+#             */
/*   Updated: 2015/10/31 17:30:04 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list *lst, int (*cmp)(t_list *, t_list *))
{
	t_list	*node_i;
	t_list	*node_j;

	node_i = lst;
	while (node_i)
	{
		node_j = node_i->next;
		while (node_j)
		{
			if ((*cmp)(node_i, node_j) > 0)
				ft_lstswap(node_i, node_j);
			node_j = node_j->next;
		}
		node_i = node_i->next;
	}
}
