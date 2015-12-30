#include "ft_printf.h"

char	*get_longlong(va_list *ap)
{
	char		*aux;
	long long	nbr;

	nbr = va_arg(*ap, long long);
	aux = ft_litoa_base(nbr, 10, "0123456789");
	return (aux);
}

char	*get_size_t(va_list *ap)
{
	size_t	nbr;
	char	*aux;

	nbr = va_arg(*ap, size_t);
	aux = ft_litoa_base(nbr, 10, "0123456789");
	return (aux);
}

char	*get_intmax_t(va_list *ap)
{
	intmax_t	nbr;
	char		*aux;

	nbr = va_arg(*ap, intmax_t);
	aux = ft_litoa_base(nbr, 10, "0123456789");
	return (aux);
}

char	*get_unsigned(va_list *ap, int base, char *trans_table)
{
	unsigned int	nbr;
	char			*aux;

	nbr = va_arg(*ap, unsigned int);
	aux = ft_utoa_base(nbr, base, trans_table);
	return (aux);
}

char	*get_unsigned_long(va_list *ap, int base, char *trans_table)
{
	unsigned long	nbr;
	char			*aux;

	nbr = va_arg(*ap, unsigned long);
	aux = ft_ultoa_base(nbr, base, trans_table);
	return (aux);
}
