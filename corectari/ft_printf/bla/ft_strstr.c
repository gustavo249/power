/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 20:31:15 by ocota             #+#    #+#             */
/*   Updated: 2015/11/13 16:46:30 by ocota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		k;
	int		ok;

	i = 0;
	while (s1[i])
	{
		k = i;
		j = 0;
		ok = 1;
		while (s2[j] && ok)
		{
			if (s1[k] != s2[j])
				ok = 0;
			k++;
			j++;
		}
		if (ok)
			return ((char*)(s1 + i));
		i++;
	}
	if (s2[0] == '\0')
		return ((char*)s1);
	return (NULL);
}
