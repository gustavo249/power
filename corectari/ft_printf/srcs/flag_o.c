#include "ft_printf.h"

int		compute_o_flag(va_list *ap, t_arg args)
{
	char	*text;

	if (args.mod_l)
		text = get_unsigned_long(ap, 8, "0123456789");
	else if (args.mod_ll)
		text = get_unsigned_longlong(ap, 8, "0123456789");
	else if (args.mod_hh)
		text = get_unsigned_hh(ap, 8, "0123456789");
	else if (args.mod_h)
		text = get_unsigned_h(ap, 8, "0123456789");
	else if (args.mod_z)
		text = get_unsigned_size_t(ap, 8, "0123456789");
	else if (args.mod_j)
		text = get_unsigned_intmax_t(ap, 8, "0123456789");
	else
		text = get_unsigned(ap, 8, "0123456789");
	return (ft_print_str(text, args, 4));
}
