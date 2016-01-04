#include "ft_printf.h"

int		try_char_flags(va_list *ap, char *flag, t_arg args)
{
	if (*flag == 's' && args.mod_l)
		return (compute_bigs_flag(ap, args));
	if (*flag == 's')
		return (compute_s_flag(ap, args));
	if (*flag == 'S')
		return (compute_bigs_flag(ap, args));
	if (*flag == 'c' && args.mod_l)
		return (compute_bigc_flag(ap, args));
	if (*flag == 'c')
		return (compute_c_flag(ap, args));
	if (*flag == 'C')
		return (compute_bigc_flag(ap, args));
	if (*flag == 'D')
	{
		args.mod_l = 1;
		return (compute_d_flag(ap, args));
	}
	if (*flag == 'U')
	{
		args.mod_l = 1;
		return (compute_u_flag(ap, args));
	}
	return (0);
}

int		try_nbr_flags(va_list *ap, char *flag, t_arg args)
{
	if (*flag == 'd' || *flag == 'i')
		return (compute_d_flag(ap, args));
	if (*flag == 'u')
		return (compute_u_flag(ap, args));
	if (*flag == 'p')
		return (compute_p_flag(ap, args));
	if (*flag == 'X')
		return (compute_bigx_flag(ap, args));
	if (*flag == 'x')
		return (compute_x_flag(ap, args));
	if (*flag == 'O')
	{
		args.mod_l = 1;
		return (compute_o_flag(ap, args));
	}
	if (*flag == 'o')
		return (compute_o_flag(ap, args));
	if (*flag == 'b')
		return (compute_b_flag(ap, args));
	if (*flag == 'f' || *flag == 'F')
		return (compute_f_flag(ap, args));
	return (0);
}

int		ft_compute_flag(va_list *ap, char *flag, t_arg args, int so_far)
{
	int		value;

	value = 0;
	value += (try_char_flags(ap, flag, args));
	value += (try_nbr_flags(ap, flag, args));
	if (*flag == 'n')
		return (compute_n_flag(ap, args, so_far));
	return (value);
}
