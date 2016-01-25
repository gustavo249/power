/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 03:57:14 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/22 16:24:56 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*str;

	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str)
	{
		i = 0;
		while (i <= size)
		{
			str[i] = '\0';
			i++;
		}
	}
	return (str);
}
