/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 11:15:34 by jfazakas          #+#    #+#             */
/*   Updated: 2015/10/31 17:37:30 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*s2 == '\0')
		return ((char*)s1);
	while (s1[i] != '\0')
	{
		j = 0;
		while (*(unsigned char*)(s1 + i + j) == *(unsigned char*)(s2 + j) &&
				*(unsigned char*)(s2 + j) != '\0' && i + j < n)
			j++;
		if (*(unsigned char*)(s2 + j) == '\0')
			return ((char*)(s1 + i));
		i++;
	}
	return (NULL);
}
