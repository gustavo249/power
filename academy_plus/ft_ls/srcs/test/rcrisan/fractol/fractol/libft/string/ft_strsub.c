/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 11:05:04 by jfazakas          #+#    #+#             */
/*   Updated: 2015/10/31 17:38:42 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	new = ft_strnew(len);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(unsigned char*)(new + i) = *(unsigned char*)(s + start + i);
		i++;
	}
	return (new);
}
