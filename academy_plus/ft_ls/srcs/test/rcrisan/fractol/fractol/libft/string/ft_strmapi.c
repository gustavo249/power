/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 17:05:24 by jfazakas          #+#    #+#             */
/*   Updated: 2015/10/31 17:36:35 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*new;
	unsigned int		i;

	new = ft_strnew(ft_strlen(s));
	i = 0;
	while (s[i] != '\0')
	{
		new[i] = (*f)(i, (char)s[i]);
		i++;
	}
	return (new);
}
