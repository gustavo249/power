/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slistnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/19 14:06:05 by jfazakas          #+#    #+#             */
/*   Updated: 2015/11/19 14:06:08 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_slist	*ft_slistnew(void *data)
{
	t_slist	*new;

	new = (t_slist*)malloc(sizeof(t_slist) * 1);
	if (!new)
		return (NULL);
	new->next = NULL;
	new->data = data;
	return (new);
}
