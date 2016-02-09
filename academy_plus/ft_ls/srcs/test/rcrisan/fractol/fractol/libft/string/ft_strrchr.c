/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 13:15:19 by jfazakas          #+#    #+#             */
/*   Updated: 2015/10/31 17:37:55 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*f;

	i = 0;
	f = NULL;
	while (s[i] != '\0')
	{
		if (*(unsigned char*)(s + i) == (unsigned char)c)
			f = (char*)(s + i);
		i++;
	}
	if (*(unsigned char*)(s + i) == (unsigned char)c)
		f = (char*)(s + i);
	return (f);
}
