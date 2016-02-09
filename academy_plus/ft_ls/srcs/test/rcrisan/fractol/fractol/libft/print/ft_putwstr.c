/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 19:30:53 by jfazakas          #+#    #+#             */
/*   Updated: 2015/12/15 19:36:05 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwstr(const wchar_t *wide_char)
{
	int		index;

	index = 0;
	while (wide_char[index] != '\0')
	{
		ft_putwchar(wide_char[index]);
		index++;
	}
}
