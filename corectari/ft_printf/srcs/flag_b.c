#include "ft_printf.h"

int		compute_b_flag(va_list *ap, t_arg args)
{
	char	*text;

	if (args.mod_l)
		text = get_unsigned_long(ap, 2, "01");
	else if (args.mod_ll)
		text = get_unsigned_longlong(ap, 2, "01");
	else if (args.mod_hh)
		text = get_unsigned_hh(ap, 2, "01");
	else if (args.mod_h)
		text = get_unsigned_h(ap, 2, "01");
	else if (args.mod_z)
		text = get_unsigned_size_t(ap, 2, "01");
	else if (args.mod_j)
		text = get_unsigned_intmax_t(ap, 2, "01");
	else
		text = get_unsigned(ap, 2, "01");
	return (ft_print_str(text, args, 0));
}
