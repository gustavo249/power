/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 16:31:31 by jfazakas          #+#    #+#             */
/*   Updated: 2015/10/31 17:36:16 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	int		i;

	new = ft_strnew(ft_strlen(s));
	i = 0;
	while (s[i] != '\0')
	{
		new[i] = (*f)((char)s[i]);
		i++;
	}
	return (new);
}
