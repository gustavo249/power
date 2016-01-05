/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 19:52:30 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/05 19:53:43 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include "../libft/libft.h"

#define FLAGS "0123456789 hljz+-.#0"

typedef struct	s_mod
{
	int		dot_mod;
	int		h_mod;
	int		hh_mod;
	int		l_mod;
	int		ll_mod;
	int		z_mod;
	int		j_mod;
	int		hash_mod;
	int		minus_mod;
	int		zero_mod;
	int		plus_mod;
	int		space_mod;
	char	flag;
	int		width;
	int		precision;
	int		procent;

}				t_mod;


int		get_width(char *format);
void	ft_printf_noflags(char *format, t_mod flag);
t_mod	check_flags(char *format);

#endif
