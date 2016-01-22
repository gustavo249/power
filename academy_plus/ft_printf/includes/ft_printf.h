/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 19:52:30 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/22 20:16:12 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <limits.h>

# define FLAGS "0123456789 *-+#0.hljz"

# define SPECIFIERS "sSpdDioOuUxXcCfF%"

typedef struct	s_mod
{
	int			dot_mod;
	int			h_mod;
	int			hh_mod;
	int			l_mod;
	int			ll_mod;
	int			z_mod;
	int			j_mod;
	int			hash_mod;
	int			minus_mod;
	int			zero_mod;
	int			plus_mod;
	int			space_mod;
	char		specifier;
	int			width;
	int			precision;
	int			procent;
	int			hash_size;
	int			width_size;
	int			precision_size;
	int			size;
	int			wld_psize;
	int			wld_wsize;
	int			wild_width;
	int			wild_precision;
	char		chr;
	char		*result;
	char		*choped;
	char		*precizie;
	char		*lungime;
	wchar_t		*wstr;
}				t_mod;

int				is_flag(const char *format, int *k);
int				is_specifier(const char *format, int *k);
char			*chop_format(const char *format, unsigned long int *i);
void			init_flags2(t_mod *flag);
void			init_flags(t_mod *flag);
void			process_precision(char *choped, t_mod *data);
void			process_hhll_mods(char *choped, t_mod *data);
void			process_mods(char *choped, t_mod *data);
int				is_mod(char c);
int				is_double_mod(char *choped, int *i);
int				validate_mod(char *choped);
void			process_specifiers2(char *choped, t_mod *data);
void			process_specifiers(char *choped, t_mod *data);
void			process_zero_mod(char *choped, t_mod *data);
void			process_dot_mod(char *choped, t_mod *data);
void			process_wildcard(char *choped, t_mod *data);
void			process_flags(char *choped, t_mod *data);
int				get_precision(char *choped);
int				get_width(char *choped);
char			*ft_utoa_base(unsigned int n, int base, char *q);
char			*ft_lutoa_base(unsigned long n, int base, char *q);
int				base(t_mod *data);
int				is_uox(t_mod *data);
void			hh_case(t_mod *data, va_list *arg);
void			h_case(t_mod *data, va_list *arg);
void			l_case_for_strings(t_mod *data, va_list *arg);
void			l_case(t_mod *data, va_list *arg);
void			ll_case(t_mod *data, va_list *arg);
void			no_case_for_strings(t_mod *data, va_list *arg);
void			no_case(t_mod *data, va_list *arg);
void			is_udo(t_mod *data, va_list *arg);
void			is_scp(t_mod *data, va_list *arg);
void			edit_based_on_mods(t_mod *data, va_list *arg);
void			stock_lungime(t_mod *data, int len);
void			stock_width(t_mod *data);
void			stock_precision(t_mod *data);
void			make_positive(t_mod *data);
void			compute_precision(t_mod *data);
void			compute_width(t_mod *data);
void			case_plus(t_mod *data);
void			case_hash(t_mod *data);
void			case_space(t_mod *data);
void			case_zero(t_mod *data);
void			case_dot(t_mod *data);
int				no_strings(t_mod *data);
void			edit_strings_precision(t_mod *data);
void			wide_precision(t_mod *data);
void			wide_width(t_mod *data);
void			wide_dot(t_mod *data);
void			edit_wide_flags(t_mod *data);
int				get_wild_precision(va_list *arg);
int				get_wild_width(va_list *arg);
char			*stock_damn_width(char *width, int len);
char			*stock_wild_width(t_mod *data, int size);
char			*stock_wild_precision(t_mod *data, int size);
void			compute_wild_precision(t_mod *data, char *precizie);
void			edit_wild_strings(t_mod *data);
void			compute_wild_width(t_mod *data, char *width);
int				who_comes_first(t_mod *data);
void			edit_wildcard_size(t_mod *data, va_list *arg);
void			edit_wildcard(t_mod *data);
void			edit_based_on_flags(t_mod *data);
char			*convert_based_on_flags(t_mod *data, va_list *arg, int *size);
int				no_procent(const char *format);
int				double_procent(t_mod *data);
int				not_wide(t_mod *data);
int				wide_characters(t_mod *data);
int				how_much_to_print(char *text, t_mod *data);
void			is_mizerie(const char *format, unsigned long int *i, \
				t_mod *data, char *choped);
void			start_engine(char *text, int *size, \
				t_mod *data, va_list *arg);
void			init_var(unsigned long int *i, int *size);
int				what_to_print(const char *format, va_list *arg);
int				ft_printf(const char *format, ...);

#endif
