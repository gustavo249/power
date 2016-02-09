/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_has_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:39:22 by azaha             #+#    #+#             */
/*   Updated: 2016/01/21 23:02:15 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		case_has_width(t_print *elements, t_flags flags)
{
	if (flags.precision > ft_strlen(elements->text))
		store_precision(elements, flags);
	if (flags.width > flags.precision)
		store_width(elements, flags);
	return (print_formated_text(elements, flags));
}
