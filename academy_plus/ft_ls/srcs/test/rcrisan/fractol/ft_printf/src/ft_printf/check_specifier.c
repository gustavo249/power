/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 16:54:54 by azaha             #+#    #+#             */
/*   Updated: 2016/01/22 09:13:08 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	check_specifier(char *dsc, va_list *ap, int *value)
{
	int	len;

	len = ft_strlen(dsc);
	if (ft_strchr(SPECIFIER, dsc[len - 1]))
		*value += process_correct_dsc(dsc, ap);
	else if (len > 1 && dsc[0] == '%' && wrong_specifier(dsc[len - 1]))
		*value += process_incorrect_dsc(dsc, ap);
}
