/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_upper_c_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 11:00:46 by azaha             #+#    #+#             */
/*   Updated: 2016/01/22 11:02:01 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	assign_upper_c(va_list *ap, t_flags flags)
{
	wchar_t	text;

	(void)flags;
	text = va_arg(*ap, int);
	ft_putwchar(text);
	return (get_wchar_len(text));
}
