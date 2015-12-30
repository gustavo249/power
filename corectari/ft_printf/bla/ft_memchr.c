/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 01:15:40 by ocota             #+#    #+#             */
/*   Updated: 2015/11/13 15:24:32 by ocota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*copy;
	size_t			i;

	i = 0;
	copy = (unsigned char*)s;
	while (i < n)
	{
		if (copy[i] == (unsigned char)c)
			return (copy + i);
		i++;
	}
	return (NULL);
}
