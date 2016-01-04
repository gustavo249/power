#include "ft_printf.h"

int		compute_c_flag(va_list *ap, t_arg args)
{
	unsigned char	chr;
	int				len;
	char			space;

	len = 1;
	space = ' ';
	if (args.flag_zero)
		space = '0';
	chr = va_arg(*ap, int);
	if (!args.flag_minus)
		while (args.width > 1)
		{
			ft_putchar(space);
			len++;
			args.width--;
		}
	ft_putchar(chr);
	while (args.width > 1)
	{
		ft_putchar(space);
		len++;
		args.width--;
	}
	return (len);
}
