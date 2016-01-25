/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:26:59 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/20 18:27:24 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wstrsize(wchar_t *wstr)
{
	int size;
	int i;

	i = 0;
	size = 0;
	while (wstr[i])
	{
		if (wstr[i] <= 127)
			size += 1;
		else if (wstr[i] <= 2047)
			size += 2;
		else if (wstr[i] <= 65535)
			size += 3;
		else if (wstr[i] <= 1114111)
			size += 4;
		i++;
	}
	return (size);
}
