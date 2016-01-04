/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 23:55:59 by ocota             #+#    #+#             */
/*   Updated: 2015/10/25 00:57:41 by ocota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	size_t			poz;
	int				ok;
	unsigned char	*c_dst;
	char			*c_src;

	c_dst = dst;
	c_src = ft_strdup(src);
	ok = 0;
	i = 0;
	while (i < n)
	{
		c_dst[i] = c_src[i];
		if (!ok)
			if (c_src[i] == c)
			{
				poz = i;
				ok = 1;
			}
		i++;
	}
	if (!ok)
		return (NULL);
	else
		return (dst + poz + 1);
}
