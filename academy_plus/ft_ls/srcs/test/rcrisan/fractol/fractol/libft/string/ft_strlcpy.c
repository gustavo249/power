/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 15:49:05 by jfazakas          #+#    #+#             */
/*   Updated: 2015/10/31 17:35:50 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;

	index = 0;
	while (index + 1 < size)
	{
		*(unsigned char*)(dst + index) = *(unsigned char*)(src + index);
		index++;
	}
	if (index < size)
		dst[index] = '\0';
	return (ft_strlen(src));
}
