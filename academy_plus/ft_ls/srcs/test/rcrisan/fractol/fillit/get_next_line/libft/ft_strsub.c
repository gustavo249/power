/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 18:52:43 by azaha             #+#    #+#             */
/*   Updated: 2015/11/09 18:46:14 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*rez;
	size_t	index;

	index = 0;
	if (!(rez = (char*)malloc(sizeof(*rez) * (len + 1))))
		return (NULL);
	while (index < len)
	{
		rez[index] = s[start + index];
		index++;
	}
	rez[index] = '\0';
	return (rez);
}
