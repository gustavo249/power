/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_p_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 22:05:13 by azaha             #+#    #+#             */
/*   Updated: 2016/01/22 13:58:09 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	assign_p(va_list *ap, t_flags flags)
{
	void	*ptr;
	t_print	elements;

	init_elements(&elements);
	ptr = va_arg(*ap, void*);
	elements.text = ft_ulltoa_base((unsigned long long)ptr,
			16, "0123456789abcdef");
	flags.hash = 1;
	elements.sign = ft_strdup("0x");
	if (flags.dot && ft_strequ(elements.text, "0"))
		elements.text = ft_strdup("");
	return (get_width_precision(&elements, flags));
}
