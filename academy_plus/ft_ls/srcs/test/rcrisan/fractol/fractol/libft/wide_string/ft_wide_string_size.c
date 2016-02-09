/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wide_string_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 13:11:53 by jfazakas          #+#    #+#             */
/*   Updated: 2015/12/16 18:24:03 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_wide_string_size(const wchar_t *wide_string)
{
	unsigned int	size;
	unsigned int	index;

	if (!wide_string)
		return (0);
	size = 0;
	index = 0;
	while (wide_string[index] != '\0')
	{
		size += ft_wide_char_size(wide_string[index]);
		index++;
	}
	return (size);
}
