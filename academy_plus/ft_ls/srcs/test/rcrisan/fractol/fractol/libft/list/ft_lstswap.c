/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 13:13:19 by jfazakas          #+#    #+#             */
/*   Updated: 2015/11/19 14:05:41 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstswap(t_list *a, t_list *b)
{
	void	*tmpv;
	size_t	tmps;

	tmpv = a->content;
	a->content = b->content;
	b->content = tmpv;
	tmps = a->content_size;
	a->content_size = b->content_size;
	b->content_size = tmps;
}
