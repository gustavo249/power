/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 23:05:36 by ocota             #+#    #+#             */
/*   Updated: 2015/11/14 02:42:55 by ocota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*copy;
	int		i;
	int		size;

	size = ft_strlen(s);
	if (!(copy = (char*)malloc(sizeof(*s) * size + 1)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		copy[i] = (*f)(s[i]);
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
