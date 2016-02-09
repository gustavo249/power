/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plistdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <jfazakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 01:10:38 by jfazakas          #+#    #+#             */
/*   Updated: 2016/01/10 01:17:36 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_plistdel(t_plist **begin)
{
	t_plist	*node;
	t_plist	*prev;

	node = (*begin);
	prev = NULL;
	while (node)
	{
		prev = node;
		node = node->next;
		free(prev);
	}
	*begin = NULL;
}
