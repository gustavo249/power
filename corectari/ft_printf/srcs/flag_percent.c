#include "ft_printf.h"

int		compute_percent_flag(va_list *ap, t_arg args)
{
	ft_putchar('%');
	(void)args;
	(void)ap;
	return (1);
}
