#include "ft_printf.h"

char	*get_unsigned_longlong(va_list *ap, int base, char *trans_table)
{
	unsigned long long	nbr;
	char				*aux;

	nbr = va_arg(*ap, unsigned long long);
	aux = ft_ultoa_base(nbr, base, trans_table);
	return (aux);
}

char	*get_unsigned_hh(va_list *ap, int base, char *trans_table)
{
	unsigned char	chr;
	char			*aux;

	chr = va_arg(*ap, unsigned int);
	aux = ft_uctoa_base(chr, base, trans_table);
	return (aux);
}

char	*get_unsigned_h(va_list *ap, int base, char *trans_table)
{
	unsigned short	chr;
	char			*aux;

	chr = va_arg(*ap, unsigned int);
	aux = ft_ustoa_base(chr, base, trans_table);
	return (aux);
}

char	*get_unsigned_size_t(va_list *ap, int base, char *trans_table)
{
	size_t	nbr;
	char	*aux;

	nbr = va_arg(*ap, size_t);
	aux = ft_ultoa_base(nbr, base, trans_table);
	return (aux);
}

char	*get_unsigned_intmax_t(va_list *ap, int base, char *trans_table)
{
	intmax_t	nbr;
	char		*aux;

	nbr = va_arg(*ap, intmax_t);
	aux = ft_ultoa_base(nbr, base, trans_table);
	return (aux);
}
