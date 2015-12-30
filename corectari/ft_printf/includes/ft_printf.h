#ifndef __FT_PRINTF_H
# define __FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

# define KNOWN_FLAGS "sSpdDioOuUxXcCbfFn%"
# define INNER_FLAGS "0123456789.#hljz+- *"

typedef struct		s_arg
{
	char			flag_hash;
	char			flag_zero;
	char			flag_plus;
	char			flag_minus;
	char			flag_space;
	char			flag_dot;
	char			flag_wild;
	char			mod_h;
	char			mod_hh;
	char			mod_l;
	char			mod_ll;
	char			mod_j;
	char			mod_z;
	unsigned int	width;
	unsigned int	dot_width;
}					t_arg;

int		ft_printf(const char *format, ...);
int		ft_correct_flag(va_list *ap, char *flag, int so_far);
int		ft_incorrect_flag(va_list *ap, char *flag);
int		ft_compute_flag(va_list *ap, char *flag, t_arg args, int so_far);
int		ft_compute_incorrect_flag(char *flag, t_arg args);
int		compute_s_flag(va_list *ap, t_arg args);
int		compute_bigs_flag(va_list *ap, t_arg args);
int		compute_c_flag(va_list *ap, t_arg args);
int		compute_b_flag(va_list *ap, t_arg args);
int		compute_n_flag(va_list *ap, t_arg args, int value);
int		compute_bigc_flag(va_list *ap, t_arg args);
int		compute_d_flag(va_list *ap, t_arg args);
int		compute_f_flag(va_list *ap, t_arg args);
int		compute_u_flag(va_list *ap, t_arg args);
int		compute_U_flag(va_list *ap, t_arg args);
int		compute_p_flag(va_list *ap, t_arg args);
int		compute_x_flag(va_list *ap, t_arg args);
int		compute_x_long_flag(va_list *ap, t_arg args);
int		compute_bigx_flag(va_list *ap, t_arg args);
int		compute_o_flag(va_list *ap, t_arg args);
int		compute_bigo_flag(va_list *ap, t_arg args);
int		compute_wchar_length(wchar_t chr);

char	*ft_itoa_base(int n, int base, char *trans_table);
char	*ft_litoa_base(long n, int base, char *trans_table);
char	*ft_sitoa_base(short int n, int base, char *trans_table);
char	*ft_citoa_base(char n, int base, char *trans_table);
void	ft_putwchar(wchar_t chr);
char	*ft_utoa_base(unsigned int n, int base, char *trans_table);
char	*ft_ultoa_base(unsigned long n, int base, char *trans_table);
char	*ft_ustoa_base(unsigned short n, int base, char *trans_table);
char	*ft_uctoa_base(unsigned char n, int base, char *trans_table);

char	*get_integer(va_list *ap);
char	*get_int_hh(va_list *ap);
char	*get_int_h(va_list *ap);
char	*get_longint(va_list *ap);
char	*get_longlong(va_list *ap);
char	*get_intmax_t(va_list *ap);
char	*get_size_t(va_list *ap);
char	*get_unsigned(va_list *ap, int base, char *trans_table);
char	*get_unsigned_long(va_list *ap, int base, char *trans_table);
char	*get_unsigned_longlong(va_list *ap, int base, char *trans_table);
char	*get_unsigned_hh(va_list *ap, int base, char *trans_table);
char	*get_unsigned_h(va_list *ap, int base, char *trans_table);
char	*get_unsigned_size_t(va_list *ap, int base, char *trans_table);
char	*get_unsigned_intmax_t(va_list *ap, int base, char *trans_table);

int		ft_print_str(char *text, t_arg args, int is_signed);
int		ft_is_special_flag(char c);
void	init_args(t_arg *args);
void	ft_verif_flag_flags(char **flag, t_arg *args);
void	ft_verif_has_mod(char **flag, t_arg *args);
void	ft_verif_precision( char **flag, t_arg *args);
void	ft_verif_wildcard(va_list *ap, char **flag, t_arg *args);
void	ft_verif_wildprecision(va_list *ap, char **flag, t_arg *args);
char	*compute_precision(char *text, t_arg args);
char	*ft_compute_sign(char *text, t_arg args);
char	*ft_compute_width(char *text, t_arg args);
char	ft_store_sign(char **text);
char	*ft_put_sign_back(char *text, char sgn);

#endif