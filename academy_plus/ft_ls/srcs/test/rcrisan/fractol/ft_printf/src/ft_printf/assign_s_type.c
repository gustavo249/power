/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_s_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 23:03:08 by azaha             #+#    #+#             */
/*   Updated: 2016/01/22 13:58:40 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		check_if_null(char *str, va_list *ap)
{
	if (!str || *ap == 0)
		return (1);
	else
		return (0);
}

static	void	trim_string(t_print *elements, t_flags flags)
{
	if (flags.precision > 0 && flags.precision < ft_strlen(elements->text))
		elements->text = ft_strsub(elements->text, 0, flags.precision);
	if (flags.precision == 0 && flags.dot == 1)
		elements->text = ft_strdup("");
}

static	void	store_s_width(t_print *elements, t_flags flags)
{
	int	len;

	len = flags.width - ft_strlen(elements->text);
	if (len > 0)
	{
		elements->width = ft_memalloc(len + 1);
		if (flags.zero)
			elements->width = ft_memset(elements->width, '0', len);
		else
			elements->width = ft_memset(elements->width, ' ', len);
	}
}

int				assign_s(va_list *ap, t_flags flags)
{
	char	*str;
	t_print	elements;

	init_elements(&elements);
	str = va_arg(*ap, char*);
	if (check_if_null(str, ap))
		elements.text = ft_strdup("(null)");
	else
		elements.text = ft_strdup(str);
	trim_string(&elements, flags);
	store_s_width(&elements, flags);
	return (print_formated_text(&elements, flags));
}
