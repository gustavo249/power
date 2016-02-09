/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 17:28:13 by jfazakas          #+#    #+#             */
/*   Updated: 2015/10/31 17:36:43 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	index_a;
	size_t	index_b;

	index_a = 0;
	while (s1[index_a] != '\0')
		index_a++;
	index_b = 0;
	while (s2[index_b] != '\0' && index_b < n)
	{
		*(unsigned char*)(s1 + index_a + index_b) =
			*(unsigned char*)(s2 + index_b);
		index_b++;
	}
	*(unsigned char*)(s1 + index_a + index_b) = '\0';
	return (s1);
}
