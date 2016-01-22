/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_stage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:16:08 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/22 15:17:59 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		no_procent(const char *format)
{
	if (ft_strchr(format, '%') == NULL)
	{
		ft_putstr(format);
		return (1);
	}
	return (0);
}

int		double_procent(t_mod *data)
{
	if (data->procent == 1)
	{
		ft_putchar('%');
		return (1);
	}
	return (0);
}

int		not_wide(t_mod *data)
{
	if (data->specifier == 'S' || data->specifier == 'C')
		return (1);
	else if (data->hh_mod == 1 && data->specifier == 'C')
		return (1);
	else if (data->l_mod == 1 && (data->specifier == 's' || \
				data->specifier == 'c'))
		return (1);
	return (0);
}

int		wide_characters(t_mod *data)
{
	int len;

	len = 0;
	if (data->wstr[0] == '\0' && data->specifier != 'S')
	{
		ft_putchar('\0');
		len++;
	}
	len = len + ft_wstrsize(data->wstr);
	ft_putwstr(data->wstr);
	return (len);
}

int		how_much_to_print(char *text, t_mod *data)
{
	int len;

	len = 0;
	if (data->specifier == 'c' && data->chr == '\0' && data->wld_wsize == -15)
	{
		ft_putchar('\0');
		len = 14;
	}
	else if (!not_wide(data))
	{
		ft_putstr(text);
		len = ft_strlen(data->result);
	}
	else
		len = wide_characters(data);
	if (double_procent(data))
		len++;
	if (data->chr == '\0')
		ft_putchar('\0');
	free(data->result);
	return (len);
}
