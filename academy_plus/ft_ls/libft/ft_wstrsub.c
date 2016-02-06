/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 19:07:52 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/20 19:10:10 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wstrsub(wchar_t *s, unsigned int start, size_t len)
{
	wchar_t	*dst;
	size_t	i;
	int		len2;

	len2 = (int)len;
	if (!(dst = (wchar_t*)malloc(sizeof(*dst) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = s[start + i];
		i++;
		len = len - ft_wcharsize(s[i]);
	}
	dst[i] = '\0';
	if (ft_wstrsize(dst) + ft_wcharsize(s[start + i]) <= len2)
	{
		dst[i] = s[start + i];
		dst[i + 1] = '\0';
	}
	return (dst);
}
