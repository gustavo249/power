/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_structures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 11:10:51 by azaha             #+#    #+#             */
/*   Updated: 2016/01/21 15:37:02 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_flags(t_flags *flags)
{
	flags->dot = 0;
	flags->hash = 0;
	flags->zero = 0;
	flags->plus = 0;
	flags->minus = 0;
	flags->space = 0;
	flags->mod_h = 0;
	flags->mod_hh = 0;
	flags->mod_l = 0;
	flags->mod_ll = 0;
	flags->mod_j = 0;
	flags->mod_z = 0;
	flags->width = 0;
	flags->precision = 0;
}

void	init_elements(t_print *elements)
{
	elements->space = ft_strdup("");
	elements->plus = ft_strdup("");
	elements->minus = ft_strdup("");
	elements->text = ft_strdup("");
	elements->sign = ft_strdup("");
	elements->width = ft_strdup("");
	elements->precision = ft_strdup("");
}
