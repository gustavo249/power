/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_wide_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:30:17 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/22 15:31:43 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	wide_precision(t_mod *data)
{
	int		p_size;
	int		len;
	wchar_t *aux;

	aux = (wchar_t*)malloc(sizeof(wchar_t) * ft_wstrsize(data->wstr));
	p_size = get_precision(data->choped);
	len = ft_wstrsize(data->wstr);
	if (p_size < ft_wcharsize(data->wstr[0]))
		data->wstr = ft_wstrdup(L"");
	else if (p_size < len)
	{
		aux = ft_wstrsub(data->wstr, 0, p_size);
		data->wstr = ft_wstrdup(L"");
		data->wstr = ft_wstrdup(aux);
	}
}

void	wide_width(t_mod *data)
{
	int		sum;
	int		i;
	wchar_t	*width;

	i = 0;
	width = (wchar_t*)malloc(sizeof(wchar_t) * get_width(data->choped));
	if (ft_strcmp("(null)", (char*)data->wstr) == 0)
		sum = get_width(data->choped);
	else
		sum = get_width(data->choped) - ft_wstrsize(data->wstr);
	if (sum > 0)
	{
		while (i < sum)
		{
			if (data->zero_mod == 1)
				width[i++] = '0';
			else
				width[i++] = ' ';
		}
		width[i] = '\0';
		if (data->minus_mod == 1)
			data->wstr = ft_wstrjoin(data->wstr, width);
		else
			data->wstr = ft_wstrjoin(width, data->wstr);
	}
}

void	wide_dot(t_mod *data)
{
	if (data->specifier != 'C')
		data->wstr = ft_wstrdup(L"");
}

void	edit_wide_flags(t_mod *data)
{
	if (data->precision == 1)
		wide_precision(data);
	if (data->dot_mod == 1)
		wide_dot(data);
	if (data->width == 1)
		wide_width(data);
}
