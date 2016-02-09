/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 18:14:36 by jfazakas          #+#    #+#             */
/*   Updated: 2015/10/31 17:29:22 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*iter;

	iter = f(lst);
	new = iter;
	while (lst->next)
	{
		lst = lst->next;
		iter->next = (*f)(lst);
		iter = iter->next;
		if (iter == NULL)
			return (NULL);
	}
	return (new);
}
