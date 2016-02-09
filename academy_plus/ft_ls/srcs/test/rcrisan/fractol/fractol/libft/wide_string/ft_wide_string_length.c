/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wide_string_length.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 13:13:18 by jfazakas          #+#    #+#             */
/*   Updated: 2015/12/16 18:23:15 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_wide_string_length(const wchar_t *wide_string)
{
	unsigned int	length;

	if (!wide_string)
		return (0);
	length = 0;
	while (wide_string[length] != '\0')
		length++;
	return (length);
}
