/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 15:39:46 by azaha             #+#    #+#             */
/*   Updated: 2015/11/09 18:06:40 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dst_len;
	size_t src_len;
	size_t length;

	length = 0;
	src_len = 0;
	dst_len = ft_strlen(dst);
	length = dst_len;
	if (size < length)
		return (ft_strlen(src) + size);
	if (size == length)
		return (ft_strlen(src) + length);
	else
	{
		while (src[src_len] && src_len < size - length - 1)
		{
			dst[dst_len] = src[src_len];
			dst_len++;
			src_len++;
		}
		dst[dst_len] = '\0';
	}
	return (length + ft_strlen(src));
}
