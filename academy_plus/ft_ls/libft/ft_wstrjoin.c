/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 16:27:28 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/20 16:38:46 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wstrjoin(wchar_t const *s1, wchar_t const *s2)
{
	wchar_t	*dst;
	int		i;
	int		j;

	dst = (wchar_t*)malloc(sizeof(*dst) * (ft_wstrlen(s1) +
				ft_wstrlen(s2) + 1));
	if (!dst)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
	{
		dst[i] = s1[j];
		j++;
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dst[i] = s2[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
