/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/14 03:17:57 by ocota             #+#    #+#             */
/*   Updated: 2015/11/14 03:49:53 by ocota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_list;

	if (!(new_list = (t_list*)malloc(sizeof(new_list) * content_size)))
		return (NULL);
	if (content)
	{
		new_list->content = (void*)content;
		new_list->content_size = content_size;
		new_list->next = NULL;
	}
	else
	{
		new_list->content = NULL;
		new_list->content_size = 0;
		new_list->next = NULL;
	}
	return (new_list);
}
