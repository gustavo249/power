/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 14:20:04 by jfazakas          #+#    #+#             */
/*   Updated: 2015/10/31 17:34:51 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int	index;

	index = 0;
	if (!src)
		return (dest);
	while (src[index] != '\0')
	{
		*(unsigned char*)(dest + index) = *(unsigned char*)(src + index);
		index++;
	}
	*(unsigned char*)(dest + index) = *(unsigned char*)(src + index);
	return (dest);
}
