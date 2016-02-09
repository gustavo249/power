/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_sum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 15:24:44 by azaha             #+#    #+#             */
/*   Updated: 2016/01/22 14:00:12 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	element_sum(t_print *elements)
{
	int	minus_plus;
	int	space_text;
	int	sign;
	int	width_prec;
	int total;

	minus_plus = ft_strlen(elements->minus) + ft_strlen(elements->plus);
	space_text = ft_strlen(elements->space) + ft_strlen(elements->text);
	sign = ft_strlen(elements->sign);
	width_prec = ft_strlen(elements->width) + ft_strlen(elements->precision);
	total = sign + width_prec + minus_plus + space_text;
	return (total);
}
