/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 17:09:40 by azaha             #+#    #+#             */
/*   Updated: 2015/11/06 18:51:35 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *map;
	char *ptr;

	if (!(map = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		map = NULL;
	else
	{
		ptr = map;
		while (*s)
		{
			*ptr = f(*s);
			ptr++;
			s++;
		}
		*ptr = '\0';
	}
	return (map);
}
