/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 09:44:04 by jfazakas          #+#    #+#             */
/*   Updated: 2015/12/16 18:33:16 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		if (*(unsigned char*)(s1 + index) != *(unsigned char*)(s2 + index))
		{
			return (*(unsigned char *)(s1 + index) -
					*(unsigned char *)(s2 + index));
		}
		index++;
	}
	return (0);
}
