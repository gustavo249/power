/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 12:56:02 by jfazakas          #+#    #+#             */
/*   Updated: 2015/10/31 17:34:20 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (*(unsigned char*)(s + i) == (unsigned char)c)
			return ((char*)(s + i));
		i++;
	}
	if (*(unsigned char*)(s + i) == (unsigned char)c)
		return ((char*)(s + i));
	return (NULL);
}
