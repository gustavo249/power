/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 12:33:00 by azaha             #+#    #+#             */
/*   Updated: 2015/11/11 17:54:22 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			index;
	unsigned char	*temp;

	if (!(temp = (unsigned char*)malloc(sizeof(*temp) * (len + 1))))
		return (NULL);
	index = 0;
	while (index < len)
	{
		*(temp + index) = *(unsigned char*)(src + index);
		index++;
	}
	index = 0;
	while (index < len)
	{
		*(unsigned char*)(dst + index) = *(temp + index);
		index++;
	}
	free(temp);
	return (dst);
}
