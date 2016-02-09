/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 14:35:34 by azaha             #+#    #+#             */
/*   Updated: 2015/10/25 14:43:31 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (s && i < n)
	{
		if (*(unsigned char*)(s + i) == (unsigned char)c)
			return ((unsigned char*)(s + i));
		else
			i++;
	}
	return (0);
}
