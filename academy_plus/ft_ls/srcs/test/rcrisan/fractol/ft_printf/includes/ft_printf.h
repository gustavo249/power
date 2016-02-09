/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 13:11:52 by azaha             #+#    #+#             */
/*   Updated: 2016/01/22 14:08:31 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# define SPECIFIER "sSpdDioOuUxXcC"
# define FLAGS "0123456789 hljz#+-."

typedef	struct		s_flags
{
	int				dot;
	int				hash;
	int				zero;
	int				plus;
	int				minus;
	int				space;
	int				mod_h;
	int				mod_hh;
	int				mod_l;
	int				mod_ll;
	int				mod_j;
	int				mod_z;
	unsigned int	width;
	unsigned int	precision;
	char			idenfitier;
}					t_flags;

typedef	struct		s_print
{
	char			*space;
	char			*plus;
	char			*minus;
	char			*text;
	char			*sign;
	char			*width;
	char			*precision;
}					t_print;

int					ft_printf(const char *format, ...);
int					parse_format(const char *format, va_list *ap);
void				check_specifier(char *dsc, va_list *ap, int	*value);
void				check_flags(char **dsc, t_flags *flags);
void				check_mods(char **dsc, t_flags *flags);
void				check_numbers(char **dsc, t_flags *flags);
int					get_specifier(char *dsc, va_list *ap, t_flags flags);
int					set_d_mod(va_list *ap, t_flags flags);
int					set_x_mod(va_list *ap, t_flags flags);
int					set_o_mod(va_list *ap, t_flags flags);
int					set_u_mod(va_list *ap, t_flags flags);
int					set_p_mod(va_list *ap, t_flags flags);
int					set_upper_d_mod(va_list *ap, t_flags flags);
int					set_upper_x_mod(va_list *ap, t_flags flags);
int					set_upper_o_mod(va_list *ap, t_flags flags);
int					set_upper_u_mod(va_list *ap, t_flags flags);
void				init_flags(t_flags *flags);
void				init_elements(t_print *elements);
int					assign_s(va_list *ap, t_flags flags);
int					assign_upper_c(va_list *ap, t_flags flags);
int					assign_upper_s(va_list *ap, t_flags flags);
int					assign_p(va_list *ap, t_flags flags);
int					assign_c(va_list *ap, t_flags flags);
int					assign_hhd(va_list *ap, t_print *elements, t_flags flags);
int					assign_ld(va_list *ap, t_print *elements, t_flags flags);
int					assign_lld(va_list *ap, t_print *elements, t_flags flags);
int					assign_hd(va_list *ap, t_print *elements, t_flags flags);
int					assign_jd(va_list *ap, t_print *elements, t_flags flags);
int					assign_zd(va_list *ap, t_print *elements, t_flags flags);
int					assign_d(va_list *ap, t_print *elements, t_flags flags);
int					assign_hhx(va_list *ap, t_print *elements, t_flags flags);
int					assign_lx(va_list *ap, t_print *elements, t_flags flags);
int					assign_llx(va_list *ap, t_print *elements, t_flags flags);
int					assign_hx(va_list *ap, t_print *elements, t_flags flags);
int					assign_x(va_list *ap, t_print *elements, t_flags flags);
int					assign_hho(va_list *ap, t_print *elements, t_flags flags);
int					assign_lo(va_list *ap, t_print *elements, t_flags flags);
int					assign_llo(va_list *ap, t_print *elements, t_flags flags);
int					assign_ho(va_list *ap, t_print *elements, t_flags flags);
int					assign_o(va_list *ap, t_print *elements, t_flags flags);
int					assign_upper_hhx(va_list *ap, t_print *elements,
		t_flags flags);
int					assign_upper_hx(va_list *ap, t_print *elements,
		t_flags flags);
int					assign_upper_llx(va_list *ap, t_print *elements,
		t_flags flags);
int					assign_upper_lx(va_list *ap, t_print *elements,
		t_flags flags);
int					assign_upper_x(va_list *ap, t_print *elements,
		t_flags flags);
int					assign_uhh(va_list *ap, t_print *elements, t_flags flags);
int					assign_uh(va_list *ap, t_print *elements, t_flags flags);
int					assign_ull(va_list *ap, t_print *elements, t_flags flags);
int					assign_ul(va_list *ap, t_print *elements, t_flags flags);
int					assign_u(va_list *ap, t_print *elements, t_flags flags);
int					assign_uj(va_list *ap, t_print *elements, t_flags flags);
int					assign_uz(va_list *ap, t_print *elements, t_flags flags);
void				store_o_hash(t_print *elements, t_flags flags);
void				store_x_hash(t_print *elements, t_flags flags);
void				store_upper_x_hash(t_print *elements, t_flags flags);
void				store_width(t_print *elements, t_flags flags);
void				store_precision(t_print *elements, t_flags flags);
void				store_hh_text(char nbr, t_print *elements, t_flags flags);
void				store_l_text(long nbr, t_print *elements, t_flags flags);
void				store_ll_text(long long nbr, t_print *elements,
		t_flags flags);
void				store_h_text(short nbr, t_print *elements, t_flags flags);
void				store_int_text(int nbr, t_print *elements, t_flags flags);
int					print_formated_text(t_print *elements, t_flags flags);
int					process_correct_dsc(char *dsc, va_list *ap);
int					process_incorrect_dsc(char *dsc, va_list *ap);
int					wrong_specifier(char c);
int					get_wchar_len(wchar_t chr);
int					get_width_precision(t_print *elements, t_flags flags);
int					case_has_width(t_print *elements, t_flags flags);
int					case_precision(t_print *elements, t_flags flags);
unsigned int		ft_wstrlen(wchar_t *str);
void				ft_putwstr(wchar_t *str);
void				ft_putwchar(wchar_t chr);
int					element_sum(t_print *elements);
wchar_t				*ft_wstrsub(wchar_t *str, unsigned int start,
		unsigned int len);
#endif
