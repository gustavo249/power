/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 13:11:05 by azaha             #+#    #+#             */
/*   Updated: 2016/01/22 13:46:41 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*ft_wstrsub(wchar_t *str, unsigned int start, unsigned int len)
{
	size_t			i;
	wchar_t			*new;
	unsigned int	this;

	this = 0;
	new = ft_memalloc(sizeof(wchar_t) * (len + 1));
	if (new)
	{
		i = 0;
		while (this + get_wchar_len(str[i + start]) <= len)
		{
			new[i] = str[i + start];
			this += get_wchar_len(new[i]);
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}
