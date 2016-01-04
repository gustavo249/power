#include "ft_printf.h"

int		ft_print_str(char *text, t_arg args, int is_signed)
{
	if (args.flag_dot && is_signed != 10)
		text = compute_precision(text, args);
	if (args.flag_dot && args.dot_width == 0 &&
			text[0] == '0' && is_signed != 10)
		text[0] = '\0';
	if (is_signed == 1 || is_signed == 10)
		text = ft_compute_sign(text, args);
	if (is_signed == 2 && args.flag_hash && text[0] != '\0')
		if (!(ft_strlen(text) == 1 && text[0] == '0'))
			text = ft_strjoin("0x", text);
	if (is_signed == 3 && args.flag_hash && text[0] != '\0')
		if (!(ft_strlen(text) == 1 && text[0] == '0'))
			text = ft_strjoin("0X", text);
	if (is_signed == 4 && args.flag_hash && text[0] != '0')
		text = ft_strjoin("0", text);
	if (is_signed == 5)
		text = ft_strjoin("0x", text);
	if (args.width)
		text = ft_compute_width(text, args);
	ft_putstr(text);
	return (ft_strlen(text));
}

int		compute_d_flag(va_list *ap, t_arg args)
{
	char	*text;

	if (args.mod_l)
		text = get_longint(ap);
	else if (args.mod_z)
		text = get_size_t(ap);
	else if (args.mod_j)
		text = get_intmax_t(ap);
	else if (args.mod_hh)
		text = get_int_hh(ap);
	else if (args.mod_h)
		text = get_int_h(ap);
	else if (args.mod_ll)
		text = get_longlong(ap);
	else
		text = get_integer(ap);
	return (ft_print_str(text, args, 1));
}

int		compute_u_flag(va_list *ap, t_arg args)
{
	char	*text;

	if (args.mod_l)
		text = get_unsigned_long(ap, 10, "0123456789");
	else if (args.mod_ll)
		text = get_unsigned_longlong(ap, 10, "0123456789");
	else if (args.mod_hh)
		text = get_unsigned_hh(ap, 10, "0123456789");
	else if (args.mod_h)
		text = get_unsigned_h(ap, 10, "0123456789");
	else if (args.mod_z)
		text = get_unsigned_size_t(ap, 10, "0123456789");
	else if (args.mod_j)
		text = get_unsigned_intmax_t(ap, 10, "0123456789");
	else
		text = get_unsigned(ap, 10, "0123456789");
	return (ft_print_str(text, args, 0));
}
