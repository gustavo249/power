/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 19:52:30 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/21 19:31:18 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define FLAGS "0123456789 *-+#0.hljz"

#define SPECIFIERS "sSpdDioOuUxXcCfF%"

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
	char	specifier;
	int		width;
	int		precision;
	int		procent;
	int		hash_size;
	int		width_size;
	int		precision_size;
	int		size;
	int		wld_psize;
	int		wld_wsize;
	int		wild_width;
	int		wild_precision;
	char	chr;
	char	*result;
	char	*choped;
	char	*precizie;
	char	*lungime;
	wchar_t *wstr;
}				t_mod;


#endif
