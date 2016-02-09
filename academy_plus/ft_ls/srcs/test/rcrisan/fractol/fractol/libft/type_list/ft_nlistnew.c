/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nlistnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <jfazakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 22:48:05 by jfazakas          #+#    #+#             */
/*   Updated: 2016/01/09 22:48:06 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_nlist	*ft_nlistnew(int value)
{
	t_nlist	*new;

	new = malloc(sizeof(t_nlist));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->value = value;
	return (new);
}
