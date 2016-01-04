#include "ft_printf.h"

void	ft_verif_wildcard(va_list *ap, char **flag, t_arg *args)
{
	int		nbr;

	if (**flag == '*')
	{
		nbr = va_arg(*ap, int);
		if (nbr >= 0)
			args->width = nbr;
		else
		{
			args->width = -nbr;
			args->flag_minus = 1;
		}
	}
}

void	ft_verif_wildprecision(va_list *ap, char **flag, t_arg *args)
{
	int		nbr;

	if (**flag == '.' && *(*flag + 1) == '*')
	{
		nbr = va_arg(*ap, int);
		if (nbr > 0)
		{
			args->flag_dot = 1;
			args->dot_width = nbr;
		}
		else
		{
			args->flag_wild = 1;
			args->dot_width = -nbr;
		}
		(*flag)++;
	}
}
