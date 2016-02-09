/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 14:00:50 by azaha             #+#    #+#             */
/*   Updated: 2016/01/22 14:01:00 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_width_precision(t_print *elements, t_flags flags)
{
	if (flags.width > ft_strlen(elements->text))
		return (case_has_width(elements, flags));
	if (flags.precision > ft_strlen(elements->text))
		return (case_precision(elements, flags));
	return (print_formated_text(elements, flags));
}
