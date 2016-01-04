#include "ft_printf.h"

char	*get_integer(va_list *ap)
{
	char	*aux;
	int		nbr;

	nbr = va_arg(*ap, int);
	aux = ft_itoa(nbr);
	return (aux);
}

char	*get_longint(va_list *ap)
{
	char	*aux;
	long	nbr;

	nbr = va_arg(*ap, long);
	aux = ft_litoa_base(nbr, 10, "0123456789");
	return (aux);
}

char	*get_int_hh(va_list *ap)
{
	char	*aux;
	char	chr;

	chr = va_arg(*ap, int);
	aux = ft_citoa_base(chr, 10, "0123456789");
	return (aux);
}

char	*get_int_h(va_list *ap)
{
	char	*aux;
	short	chr;

	chr = va_arg(*ap, int);
	aux = ft_sitoa_base(chr, 10, "0123456789");
	return (aux);
}
