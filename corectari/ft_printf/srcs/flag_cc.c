#include "ft_printf.h"

int		compute_bigc_flag(va_list *ap, t_arg args)
{
	wchar_t	text;

	text = va_arg(*ap, int);
	(void)args;
	ft_putwchar(text);
	return (compute_wchar_length(text));
}
