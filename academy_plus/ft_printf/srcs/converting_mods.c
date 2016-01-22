/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converting_mods.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:45:39 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/22 15:48:36 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hh_case(t_mod *data, va_list *arg)
{
	char			decimal;
	unsigned char	other_base;
	char			*bq;

	bq = "0123456789ABCDEF";
	if (data->specifier == 'd' || data->specifier == 'i')
	{
		decimal = va_arg(*arg, int);
		data->result = ft_itoa_base(decimal, base(data));
	}
	else if (is_uox(data))
	{
		other_base = va_arg(*arg, unsigned int);
		data->result = ft_itoa_base(other_base, base(data));
	}
	else if (data->specifier == 'X')
	{
		other_base = va_arg(*arg, unsigned int);
		data->result = ft_utoa_base(other_base, base(data), bq);
	}
}

void	h_case(t_mod *data, va_list *arg)
{
	short				decimal;
	unsigned short		other_base;
	char				*bq;

	bq = "0123456789ABCDEF";
	if (data->specifier == 'd' || data->specifier == 'i')
	{
		decimal = va_arg(*arg, int);
		data->result = ft_itoa_base(decimal, base(data));
	}
	else if (is_uox(data))
	{
		other_base = va_arg(*arg, unsigned int);
		data->result = ft_itoa_base(other_base, base(data));
	}
	else if (data->specifier == 'X')
	{
		other_base = va_arg(*arg, unsigned int);
		data->result = ft_utoa_base(other_base, base(data), bq);
	}
}

void	l_case_for_strings(t_mod *data, va_list *arg)
{
	if (data->specifier == 'c')
		data->wstr[0] = va_arg(*arg, wint_t);
	else if (data->specifier == 's')
		data->wstr = va_arg(*arg, wchar_t*);
}

void	l_case(t_mod *data, va_list *arg)
{
	long			decimal;
	unsigned long	other_base;
	char			*bq;
	char			*q;

	bq = "0123456789ABCDEF";
	q = "0123456789abcdef";
	if (data->specifier == 'd' || data->specifier == 'i')
	{
		decimal = va_arg(*arg, long);
		data->result = ft_litoa(decimal);
	}
	else if (is_uox(data))
	{
		other_base = va_arg(*arg, unsigned long);
		data->result = ft_lutoa_base(other_base, base(data), q);
	}
	else if (data->specifier == 'X')
	{
		other_base = va_arg(*arg, unsigned long);
		data->result = ft_lutoa_base(other_base, base(data), bq);
	}
	l_case_for_strings(data, arg);
}

void	ll_case(t_mod *data, va_list *arg)
{
	unsigned long long int		other_base;
	long long int				decimal;
	char						*q;
	char						*bq;

	bq = "0123456789ABCDEF";
	q = "0123456789abcdef";
	if (data->specifier == 'd' || data->specifier == 'i')
	{
		decimal = va_arg(*arg, long long);
		data->result = ft_litoa(decimal);
	}
	else if (is_uox(data))
	{
		other_base = va_arg(*arg, unsigned long long);
		data->result = ft_lutoa_base(other_base, base(data), q);
	}
	else if (data->specifier == 'X')
	{
		other_base = va_arg(*arg, unsigned long long);
		data->result = ft_lutoa_base(other_base, base(data), bq);
	}
}
