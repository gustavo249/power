/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 14:36:16 by azaha             #+#    #+#             */
/*   Updated: 2016/01/22 14:06:21 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *s)
{
	int		start;
	int		end;
	char	aux;

	start = 0;
	end = ft_strlen(s) - 1;
	while (start < end)
	{
		aux = s[start];
		s[start] = s[end];
		s[end] = aux;
		start++;
		end--;
	}
	return (s);
}
