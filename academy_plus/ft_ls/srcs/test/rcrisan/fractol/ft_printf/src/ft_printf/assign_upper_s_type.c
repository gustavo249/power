/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_upper_s_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 11:17:46 by azaha             #+#    #+#             */
/*   Updated: 2016/01/22 13:46:40 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_putwstr_width(wchar_t *text, char *spaces, t_flags flags)
{
	if (flags.minus == 0)
	{
		ft_putstr(spaces);
		ft_putwstr(text);
		return (ft_strlen(spaces) + ft_wstrlen(text));
	}
	else
	{
		ft_putwstr(text);
		ft_putstr(spaces);
		return (ft_strlen(spaces) + ft_wstrlen(text));
	}
}

int			assign_upper_s(va_list *ap, t_flags flags)
{
	wchar_t	*text;
	char	*spaces;
	char	chr;

	text = va_arg(*ap, wchar_t*);
	chr = ' ';
	if (flags.zero)
		chr = '0';
	if (!text)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (flags.dot && flags.precision < ft_wstrlen(text))
		text = ft_wstrsub(text, 0, flags.precision);
	if (flags.width > ft_wstrlen(text))
	{
		spaces = ft_memalloc(flags.width - ft_wstrlen(text) + 1);
		spaces = ft_memset(spaces, chr, flags.width - ft_wstrlen(text));
		return (ft_putwstr_width(text, spaces, flags));
	}
	ft_putwstr(text);
	return (ft_wstrlen(text));
}
