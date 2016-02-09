/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wide_char_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 18:43:55 by jfazakas          #+#    #+#             */
/*   Updated: 2015/12/16 19:04:33 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_wide_char_size(wchar_t wide_char)
{
	if (wide_char <= 127)
		return (1);
	if (wide_char <= 2047)
		return (2);
	if (wide_char <= 65535)
		return (3);
	return (4);
}
