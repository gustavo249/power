/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 17:42:20 by azaha             #+#    #+#             */
/*   Updated: 2015/11/06 19:14:47 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*map;

	index = 0;
	if (!(map = (char*)malloc(sizeof(map) * (ft_strlen(s) + 1))))
		map = NULL;
	else
	{
		while (s[index])
		{
			map[index] = f(index, s[index]);
			index++;
		}
		map[index] = '\0';
	}
	return (map);
}
