/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 09:02:37 by jfazakas          #+#    #+#             */
/*   Updated: 2015/10/31 17:31:45 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	index;

	if (dst > src)
	{
		while (len > 0)
		{
			len--;
			*(unsigned char*)(dst + len) = *(unsigned char*)(src + len);
		}
	}
	else
	{
		index = 0;
		while (index < len)
		{
			*(unsigned char*)(dst + index) = *(unsigned char*)(src + index);
			index++;
		}
	}
	return (dst);
}
