/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 17:54:28 by jfazakas          #+#    #+#             */
/*   Updated: 2015/10/31 17:35:45 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_length;
	size_t	src_length;
	size_t	index;

	dst_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	index = 0;
	while (dst_length + index + 1 < size && src[index] != '\0')
	{
		*(unsigned char*)(dst + dst_length + index) =
			*(unsigned char*)(src + index);
		index++;
	}
	*(unsigned char*)(dst + dst_length + index) = '\0';
	if (size < dst_length)
		return (size + src_length);
	else
		return (src_length + dst_length);
}
