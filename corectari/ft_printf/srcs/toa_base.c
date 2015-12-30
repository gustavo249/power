#include "ft_printf.h"

char	*ft_itoa_base(int n, int base, char *trans_table)
{
	char	sgn;
	char	*aux;
	int		i;

	i = 0;
	sgn = 0;
	if (n < 0)
		sgn = 1;
	aux = ft_strnew(15);
	if (n == 0)
		aux[0] = '0';
	while (n != 0)
	{
		aux[i++] = trans_table[ft_abs(n % base)];
		n /= base;
	}
	if (sgn && base == 10)
		aux[i] = '-';
	aux = ft_strrev(aux);
	return (aux);
}

char	*ft_litoa_base(long n, int base, char *trans_table)
{
	char	sgn;
	char	*aux;
	int		i;

	i = 0;
	sgn = 0;
	if (n < 0)
		sgn = 1;
	aux = ft_strnew(32);
	if (n == 0)
		aux[0] = '0';
	while (n != 0)
	{
		aux[i++] = trans_table[ft_abs(n % base)];
		n /= base;
	}
	if (sgn && base == 10)
		aux[i] = '-';
	aux = ft_strrev(aux);
	return (aux);
}

char	*ft_sitoa_base(short int n, int base, char *trans_table)
{
	char	sgn;
	char	*aux;
	int		i;

	i = 0;
	sgn = 0;
	if (n < 0)
		sgn = 1;
	aux = ft_strnew(15);
	if (n == 0)
		aux[0] = '0';
	while (n != 0)
	{
		aux[i++] = trans_table[ft_abs(n % base)];
		n /= base;
	}
	if (sgn && base == 10)
		aux[i] = '-';
	aux = ft_strrev(aux);
	return (aux);
}

char	*ft_citoa_base(char n, int base, char *trans_table)
{
	char	sgn;
	char	*aux;
	int		i;

	i = 0;
	sgn = 0;
	if (n < 0)
		sgn = 1;
	aux = ft_strnew(15);
	if (n == 0)
		aux[0] = '0';
	while (n != 0)
	{
		aux[i++] = trans_table[ft_abs(n % base)];
		n /= base;
	}
	if (sgn && base == 10)
		aux[i] = '-';
	aux = ft_strrev(aux);
	return (aux);
}
