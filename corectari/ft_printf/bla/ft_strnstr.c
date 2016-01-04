/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 21:17:00 by ocota             #+#    #+#             */
/*   Updated: 2015/11/13 16:51:45 by ocota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!s2)
		return ((char*)s1);
	while (s1[i])
	{
		while (s2[j] == s1[i + j] && s2[j] && (i + j) < n)
			j++;
		if (s2[j] == '\0')
			return ((char*)(s1 + i));
		j = 0;
		i++;
	}
	return (NULL);
}
