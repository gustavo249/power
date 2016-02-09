/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uclistnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <jfazakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 22:48:45 by jfazakas          #+#    #+#             */
/*   Updated: 2016/01/09 22:48:46 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_uclist	*ft_uclistnew(unsigned char value)
{
	t_uclist	*new;

	new = malloc(sizeof(t_uclist));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->value = value;
	return (new);
}
