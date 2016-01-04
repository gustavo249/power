/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 23:38:42 by ocota             #+#    #+#             */
/*   Updated: 2015/11/14 03:14:56 by ocota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*copy;

	if (!(copy = (char*)malloc(len + 1)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i++] = s[start];
		start++;
	}
	copy[start] = '\0';
	return (copy);
}
