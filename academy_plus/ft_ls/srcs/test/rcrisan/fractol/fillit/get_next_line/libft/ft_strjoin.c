/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 12:05:34 by azaha             #+#    #+#             */
/*   Updated: 2015/11/19 11:42:33 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*rez;
	char	*ptr;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(rez = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ptr = rez;
	while (*s1)
	{
		*(ptr) = *(s1);
		ptr++;
		s1++;
	}
	while (*s2)
	{
		*(ptr) = *(s2);
		ptr++;
		s2++;
	}
	rez[size] = '\0';
	return (rez);
}
