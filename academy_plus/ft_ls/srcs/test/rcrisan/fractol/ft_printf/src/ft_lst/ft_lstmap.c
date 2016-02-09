/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 15:35:01 by azaha             #+#    #+#             */
/*   Updated: 2015/11/11 17:51:22 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_node;
	t_list *link;

	if (!lst)
		return (NULL);
	link = f(lst);
	if (!link)
		return (NULL);
	new_node = link;
	while (lst->next)
	{
		lst = lst->next;
		link->next = f(lst);
		if (!link->next)
			return (NULL);
		link = link->next;
	}
	return (new_node);
}
