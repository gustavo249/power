/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formated_text.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 15:21:38 by azaha             #+#    #+#             */
/*   Updated: 2016/01/22 14:01:16 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	void	print_case_minus(t_print *elements)
{
	ft_putstr(elements->space);
	ft_putstr(elements->minus);
	ft_putstr(elements->sign);
	ft_putstr(elements->precision);
	ft_putstr(elements->text);
	ft_putstr(elements->width);
}

static	void	print_case_flag_zero(t_print *elements)
{
	ft_putstr(elements->minus);
	ft_putstr(elements->plus);
	ft_putstr(elements->space);
	ft_putstr(elements->sign);
	ft_putstr(elements->width);
	ft_putstr(elements->precision);
	ft_putstr(elements->text);
}

static	void	print_case_no_zero_flag(t_print *elements)
{
	ft_putstr(elements->space);
	ft_putstr(elements->width);
	ft_putstr(elements->minus);
	ft_putstr(elements->sign);
	ft_putstr(elements->precision);
	ft_putstr(elements->plus);
	ft_putstr(elements->text);
}

int				print_formated_text(t_print *elements, t_flags flags)
{
	if (flags.minus == 1)
		print_case_minus(elements);
	else
	{
		if (flags.zero == 1)
			print_case_flag_zero(elements);
		else
			print_case_no_zero_flag(elements);
	}
	return (element_sum(elements));
}
