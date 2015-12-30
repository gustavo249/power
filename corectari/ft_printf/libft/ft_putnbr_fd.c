#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	aux;

	aux = n;
	if (aux < 0)
	{
		aux *= -1;
		ft_putchar_fd('-', fd);
	}
	if (aux > 9)
		ft_putnbr_fd(aux / 10, fd);
	ft_putchar_fd(aux % 10 + '0', fd);
}
