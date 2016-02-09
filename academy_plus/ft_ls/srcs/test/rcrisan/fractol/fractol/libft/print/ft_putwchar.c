/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 18:44:01 by jfazakas          #+#    #+#             */
/*   Updated: 2015/12/16 19:05:24 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar(wchar_t wide_char)
{
	if (wide_char <= 127)
		ft_putchar(wide_char);
	else if (wide_char <= 2047)
	{
		ft_putchar((wide_char >> 6) + 0xC0);
		ft_putchar((wide_char & 0x3F) + 0x80);
	}
	else if (wide_char <= 65535)
	{
		ft_putchar((wide_char >> 12) + 0xE0);
		ft_putchar(((wide_char >> 6) & 0x3F) + 0x80);
		ft_putchar((wide_char & 0x3F) + 0x80);
	}
	else if (wide_char <= 1114111)
	{
		ft_putchar((wide_char >> 18) + 0xF0);
		ft_putchar(((wide_char >> 12) & 0x3F) + 0x80);
		ft_putchar(((wide_char >> 6) & 0x3F) + 0x80);
		ft_putchar((wide_char & 0x3F) + 0x80);
	}
}
