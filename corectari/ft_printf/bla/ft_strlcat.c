/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 12:20:19 by ocota             #+#    #+#             */
/*   Updated: 2015/11/13 15:51:00 by ocota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t len;

	len = ft_strlen(dst);
	i = 0;
	while (dst[i])
		i++;
	j = 0;
	if (size <= len)
		return (ft_strlen(src) + size);
	else
	{
		while (src[j] && j < size - len - 1)
		{
			dst[i] = src[j];
			j++;
			i++;
		}
		dst[i] = '\0';
		return (len + ft_strlen(src));
	}
}
