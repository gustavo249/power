/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 08:37:28 by jfazakas          #+#    #+#             */
/*   Updated: 2015/10/31 17:30:37 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		*(unsigned char*)(dst + index) = *(unsigned char*)(src + index);
		if (*(unsigned char*)(dst + index) == (unsigned char)c)
			return (dst + index + 1);
		index++;
	}
	return (NULL);
}
