/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 12:00:02 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/06 13:59:21 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(t_mod *flag)
{
	flag->dot_mod = 0;
	flag->h_mod = 0;
	flag->hh_mod = 0;
	flag->l_mod = 0;
	flag->ll_mod = 0;
	flag->z_mod = 0;
	flag->j_mod = 0;
	flag->hash_mod = 0;
	flag->minus_mod = 0;
	flag->zero_mod = 0;
	flag->plus_mod = 0;
	flag->space_mod = 0;
	flag->width = 0;
	flag->identifier = (char)malloc(1);
	flag->precision = 0;
	flag->procent = 0;
}
