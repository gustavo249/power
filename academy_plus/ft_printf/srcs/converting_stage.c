/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converting_stage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:18:42 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/22 15:21:03 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		who_comes_first(t_mod *data)
{
	int i;

	i = 0;
	while (data->choped[i])
	{
		if (data->choped[i] == '*')
			break ;
		i++;
	}
	while (i >= 0)
	{
		if (ft_isdigit(data->choped[i]))
			return (0);
		i--;
	}
	return (1);
}

void	edit_wildcard_size(t_mod *data, va_list *arg)
{
	int		p_size;
	int		w_size;

	p_size = 0;
	w_size = 0;
	if (data->wild_width == 1)
	{
		w_size = get_wild_width(arg);
		if (w_size != 0)
			data->wld_wsize = w_size;
		else if (who_comes_first(data) == 0)
			data->width = 0;
	}
	if (data->wild_precision == 1)
	{
		p_size = get_wild_precision(arg);
		data->wld_psize = p_size;
	}
}

void	edit_wildcard(t_mod *data)
{
	char	*width;
	char	*precizie;

	width = ft_memalloc(data->wld_wsize);
	precizie = ft_memalloc(data->wld_psize);
	if (data->wild_precision == 1)
	{
		if (data->specifier != 's' && data->specifier != 'c')
		{
			precizie = stock_wild_precision(data, data->wld_psize);
			compute_wild_precision(data, precizie);
		}
		else
			edit_wild_strings(data);
	}
	if ((who_comes_first(data) == 0 && data->width == 1) || data->width == 0)
		if (data->wild_width == 1)
		{
			width = stock_wild_width(data, data->wld_wsize);
			compute_wild_width(data, width);
		}
}

void	edit_based_on_flags(t_mod *data)
{
	if (data->precision == 1 && data->procent == 0)
	{
		if (data->specifier != 's' && data->specifier != 'c')
		{
			stock_precision(data);
			compute_precision(data);
		}
		else
			edit_strings_precision(data);
	}
	if (data->hash_mod == 1)
		case_hash(data);
	if (data->width == 1)
		stock_width(data);
	if (data->zero_mod == 1)
		case_zero(data);
	if (data->plus_mod == 1)
		case_plus(data);
	if (data->dot_mod == 1)
		case_dot(data);
	compute_width(data);
	if (data->space_mod == 1 && data->plus_mod == 0)
		case_space(data);
	edit_wide_flags(data);
	edit_wildcard(data);
}

char	*convert_based_on_flags(t_mod *data, va_list *arg, int *size)
{
	char		*text;

	text = NULL;
	text = ft_memalloc(1000);
	edit_wildcard_size(data, arg);
	edit_based_on_mods(data, arg);
	if (data->result == NULL)
	{
		data->result = ft_memalloc(350);
		data->result = ft_strdup("(null)");
	}
	else if (data->wstr == NULL)
	{
		data->wstr = (wchar_t*)malloc(sizeof(wchar_t) * 100);
		data->wstr = L"(null)";
	}
	if ((data->result[0] == '\0' && data->specifier == 'c')\
			&& data->specifier != 's' && data->specifier != 'p')
		*size = *size + 1;
	if (data->specifier == 'c' && data->l_mod == 1)
		*size = *size - 1;
	edit_based_on_flags(data);
	text = ft_strdup(data->result);
	return (text);
}
