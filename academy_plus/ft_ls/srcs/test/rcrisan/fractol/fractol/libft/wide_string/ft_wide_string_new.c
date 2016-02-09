/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wide_string_new.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 13:22:04 by jfazakas          #+#    #+#             */
/*   Updated: 2015/12/16 18:23:31 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wide_string_new(unsigned int length)
{
	wchar_t			*wide_string;
	unsigned int	index;

	wide_string = (wchar_t*)malloc(sizeof(wchar_t) * (length + 1));
	if (!wide_string)
		return (NULL);
	index = 0;
	while (index <= length)
	{
		wide_string[index] = '\0';
		index++;
	}
	return (wide_string);
}
