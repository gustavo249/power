/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 19:52:30 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/15 13:53:02 by rcrisan          ###   ########.fr       */
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

#define FLAGS "0123456789 -+#0.hljz"

#define SPECIFIERS "sSpdDioOuUxXcC"

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
	char	*result;
	char	chr;
	wint_t	wchr;
	wchar_t *wstr;
}				t_mod;


int     is_flag(const char *format, int *k);
int     is_specifier(const char *format, int *k);
char    *chop_format(const char *format, unsigned long int *i);
void    init_flags(t_mod *flag);
void    process_precision(char  *choped, t_mod *data);
void    process_hhll_mods(char  *choped, t_mod  *data);
void    process_mods(char *choped, t_mod *data);
int     is_mod(char c);
int     is_double_mod(char  *choped, int *i);
int     validate_mod(char *choped);
void    process_specifiers2(char *choped, t_mod *data);
void    process_specifiers(char *choped, t_mod *data);
void    process_flags(char *choped, t_mod *data);
int     get_precision(char *choped);
int     get_width(char *choped);
int     get_size(char *choped, t_mod *data);
int		base(t_mod *data);
void	hh_case(t_mod *data, va_list *arg);
void	no_case_strings(t_mod *data, va_list *arg);
void	no_case(t_mod *data, va_list *arg);
void	edit_based_on_mods(t_mod *data, va_list *arg);
char    *convert_based_on_flags(t_mod *data, va_list *arg);
int     no_procent(const char *format);
int    how_much_to_print(char *choped, char *text, t_mod *data);
int     what_to_print(const char *format, va_list *arg);
int     ft_printf(const char *format, ...);

#endif
