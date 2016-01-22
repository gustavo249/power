/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converting_no_mod.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:42:46 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/22 15:44:39 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	no_case_for_strings(t_mod *data, va_list *arg)
{
	if (data->specifier == 's')
		data->result = va_arg(*arg, char*);
	else if (data->specifier == 'c')
	{
		data->chr = va_arg(*arg, int);
		data->result[0] = data->chr;
	}
}

void	no_case(t_mod *data, va_list *arg)
{
	int				decimal;
	unsigned int	other_base;

	if (data->specifier == 'd' || data->specifier == 'i')
	{
		decimal = va_arg(*arg, int);
		data->result = ft_itoa(decimal);
	}
	else if (is_uox(data))
	{
		other_base = va_arg(*arg, unsigned int);
		data->result = ft_utoa_base(other_base, base(data), "0123456789abcdef");
	}
	else if (data->specifier == 'X')
	{
		other_base = va_arg(*arg, unsigned int);
		data->result = ft_utoa_base(other_base, base(data), "0123456789ABCDEF");
	}
	no_case_for_strings(data, arg);
}

void	is_udo(t_mod *data, va_list *arg)
{
	unsigned long	other_base;
	long			decimal;
	char			*q;

	q = "0123456789abcdef";
	if (data->specifier == 'O' || data->specifier == 'U')
	{
		other_base = va_arg(*arg, unsigned long);
		data->result = ft_lutoa_base(other_base, base(data), q);
	}
	else if (data->specifier == 'D')
	{
		decimal = va_arg(*arg, long);
		data->result = ft_litoa(decimal);
	}
}

void	is_scp(t_mod *data, va_list *arg)
{
	unsigned long long p;

	p = 0;
	if (data->specifier == 'S')
		data->wstr = va_arg(*arg, wchar_t *);
	else if (data->specifier == 'C')
		data->wstr[0] = va_arg(*arg, wint_t);
	else if (data->specifier == 'p')
	{
		p = (unsigned long long)va_arg(*arg, void*);
		data->result = ft_lutoa_base(p, 16, "0123456789abcdef");
		if (data->precision == 0)
			data->result = ft_strjoin("0x", data->result);
	}
}

void	edit_based_on_mods(t_mod *data, va_list *arg)
{
	if (data->hh_mod == 1)
		hh_case(data, arg);
	else if (data->h_mod == 1)
		h_case(data, arg);
	else if (data->l_mod == 1)
		l_case(data, arg);
	else if (data->ll_mod == 1 || data->j_mod == 1 || data->z_mod == 1)
		ll_case(data, arg);
	else
		no_case(data, arg);
	is_udo(data, arg);
	is_scp(data, arg);
}
