#include "libft.h"

void	ft_putnbr(int n)
{
	long	aux;

	aux = n;
	if (aux < 0)
	{
		aux *= -1;
		ft_putchar('-');
	}
	if (aux > 9)
		ft_putnbr(aux / 10);
	ft_putchar(aux % 10 + '0');
}
