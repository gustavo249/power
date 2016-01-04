/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 23:10:40 by ocota             #+#    #+#             */
/*   Updated: 2015/11/14 02:44:24 by ocota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*copy;
	int				i;
	unsigned int	size;

	size = ft_strlen(s);
	if (!(copy = (char*)malloc(sizeof(*s) * size + 1)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		copy[i] = (*f)(i, s[i]);
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
