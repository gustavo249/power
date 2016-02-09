/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 18:20:14 by jfazakas          #+#    #+#             */
/*   Updated: 2015/10/31 17:30:30 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*mem;

	if (size == 0)
		return (NULL);
	mem = (unsigned char*)malloc(size);
	if (mem)
	{
		ft_memset(mem, 0, size);
		return ((void*)mem);
	}
	return (NULL);
}
