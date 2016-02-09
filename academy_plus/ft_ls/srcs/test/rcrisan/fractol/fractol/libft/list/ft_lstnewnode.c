/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/19 14:06:48 by jfazakas          #+#    #+#             */
/*   Updated: 2015/11/19 14:06:49 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnewnode(void *content, size_t content_size)
{
	t_list	*new;

	new = (t_list*)malloc(sizeof(t_list) * 1);
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->content = content;
	new->content_size = content_size;
	return (new);
}
