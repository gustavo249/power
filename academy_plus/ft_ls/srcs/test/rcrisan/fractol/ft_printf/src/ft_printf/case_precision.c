/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 19:24:28 by azaha             #+#    #+#             */
/*   Updated: 2016/01/20 19:30:46 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	case_precision(t_print *elements, t_flags flags)
{
	store_precision(elements, flags);
	return (print_formated_text(elements, flags));
}
