#include "ft_printf.h"

int		compute_n_flag(va_list *ap, t_arg args, int value)
{
	int		*aux;

	aux = va_arg(*ap, void*);
	(void)args;
	*aux = value;
	return (0);
}
