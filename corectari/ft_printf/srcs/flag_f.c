#include "ft_printf.h"

void	ft_add_to_aux(long *aux)
{
	if (*aux >= 0)
		*aux += 1;
	else
		*aux -= 1;
}

char	*ft_compute_real_part(double nbr, t_arg args, long *auux)
{
	unsigned int	i;
	char			*text;
	unsigned long	aux;

	i = 0;
	aux = 0;
	text = ft_memalloc(1);
	while (i < args.dot_width)
	{
		nbr *= 10;
		aux *= 10;
		i++;
		aux += (int)nbr;
		nbr -= (int)nbr;
	}
	nbr = (int)(nbr * 10);
	if (nbr >= 5 && i > 0)
		aux += 1;
	if (nbr >= 5 && i == 0)
		ft_add_to_aux(auux);
	if (i > 0)
		text = ft_ultoa_base(aux, 10, "0123456789");
	return (text);
}

char	*ft_ftoa(double nbr, t_arg args)
{
	char	*integer;
	char	*real_p;
	long	aux;

	aux = (long)nbr;
	if (args.flag_dot == 0)
	{
		args.flag_dot = 1;
		args.dot_width = 6;
	}
	nbr = nbr - (long)nbr;
	if (nbr < 0)
		nbr *= -1;
	real_p = ft_compute_real_part(nbr, args, &aux);
	integer = ft_litoa_base(aux, 10, "0123456789");
	if (real_p[0])
		integer = ft_strjoin(integer, ".");
	return (ft_strjoin(integer, real_p));
}

int		compute_f_flag(va_list *ap, t_arg args)
{
	double	nbr;
	char	*text;

	nbr = va_arg(*ap, double);
	text = ft_ftoa(nbr, args);
	return (ft_print_str(text, args, 10));
}
