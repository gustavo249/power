/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plistnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <jfazakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 00:10:55 by jfazakas          #+#    #+#             */
/*   Updated: 2016/01/10 00:17:27 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_plist		*ft_plistnew(void *pointer)
{
	t_plist	*new;

	new = malloc(sizeof(t_plist));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->pointer = pointer;
	return (new);
}
