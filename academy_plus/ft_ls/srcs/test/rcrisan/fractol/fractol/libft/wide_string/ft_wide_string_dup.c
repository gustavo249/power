/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wide_string_dup.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 00:09:48 by jfazakas          #+#    #+#             */
/*   Updated: 2015/12/16 18:28:53 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wide_string_dup(const wchar_t *wide_string)
{
	wchar_t		*duplicate;
	int			index;
	int			length;

	length = ft_wide_string_length(wide_string);
	if (!wide_string || !(duplicate = ft_wide_string_new(length)))
		return (NULL);
	index = 0;
	while (index < length)
	{
		duplicate[index] = wide_string[index];
		index++;
	}
	return (duplicate);
}
