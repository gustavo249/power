/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 16:54:14 by jfazakas          #+#    #+#             */
/*   Updated: 2015/10/31 17:34:08 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		index_a;
	int		index_b;

	index_a = 0;
	while (s1[index_a] != '\0')
		index_a++;
	index_b = 0;
	while (s2[index_b] != '\0')
	{
		*(unsigned char*)(s1 + index_a + index_b) =
			*(unsigned char*)(s2 + index_b);
		index_b++;
	}
	*(unsigned char*)(s1 + index_a + index_b) = '\0';
	return (s1);
}
