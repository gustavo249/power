#include "libft.h"

char	*ft_utoa_base(unsigned int n, int base, char *trans_table)
{
	char	*aux;
	int		i;

	i = 0;
	aux = ft_strnew(15);
	if (n == 0)
		aux[0] = '0';
	while (n != 0)
	{
		aux[i++] = trans_table[n % base];
		n /= base;
	}
	aux = ft_strrev(aux);
	return (aux);
}

char	*ft_ultoa_base(unsigned long n, int base, char *trans_table)
{
	char	*aux;
	int		i;

	i = 0;
	aux = ft_strnew(32);
	if (n == 0)
		aux[0] = '0';
	while (n != 0)
	{
		aux[i++] = trans_table[n % base];
		n /= base;
	}
	aux = ft_strrev(aux);
	return (aux);
}

char	*ft_ustoa_base(unsigned short n, int base, char *trans_table)
{
	char	*aux;
	int		i;

	i = 0;
	aux = ft_strnew(15);
	if (n == 0)
		aux[0] = '0';
	while (n != 0)
	{
		aux[i++] = trans_table[n % base];
		n /= base;
	}
	aux = ft_strrev(aux);
	return (aux);
}

char	*ft_uctoa_base(unsigned char n, int base, char *trans_table)
{
	char	*aux;
	int		i;

	i = 0;
	aux = ft_strnew(15);
	if (n == 0)
		aux[0] = '0';
	while (n != 0)
	{
		aux[i++] = trans_table[n % base];
		n /= base;
	}
	aux = ft_strrev(aux);
	return (aux);
}
