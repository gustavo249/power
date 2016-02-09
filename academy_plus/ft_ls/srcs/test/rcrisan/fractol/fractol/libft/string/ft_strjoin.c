/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 12:31:06 by jfazakas          #+#    #+#             */
/*   Updated: 2015/10/31 17:35:39 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		j;

	join = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (join == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		*(unsigned char*)(join + i) = *(unsigned char*)(s1 + i);
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		*(unsigned char*)(join + i + j) = *(unsigned char*)(s2 + j);
		j++;
	}
	return (join);
}
