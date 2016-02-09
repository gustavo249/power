/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 10:16:46 by azaha             #+#    #+#             */
/*   Updated: 2016/01/20 21:33:37 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	int	get_dsc_len(const char *format)
{
	int	dsc_len;

	dsc_len = 1;
	if (format[dsc_len] == '\0')
		return (0);
	while (ft_strchr(FLAGS, format[dsc_len]))
		dsc_len++;
	if (ft_strchr(SPECIFIER, format[dsc_len]))
		return (dsc_len);
	else if (wrong_specifier(format[dsc_len]))
		return (dsc_len);
	else
		return (dsc_len - 1);
}

int			parse_format(const char *format, va_list *ap)
{
	int		dsc_len;
	int		value;
	char	*dsc;

	value = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			dsc_len = get_dsc_len(format);
			dsc = ft_strsub(format, 0, dsc_len + 1);
			check_specifier(dsc, ap, &value);
			format += dsc_len;
		}
		else
		{
			ft_putchar(*format);
			value++;
		}
		format++;
	}
	return (value);
}
