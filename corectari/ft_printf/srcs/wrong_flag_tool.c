#include "ft_printf.h"

int		ft_is_special_flag(char c)
{
	if (c == '%')
		return (1);
	if (ft_strchr(KNOWN_FLAGS, c))
		return (0);
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int		ft_compute_incorrect_flag(char *flag, t_arg args)
{
	int		len;
	char	space;

	len = 1;
	space = ' ';
	if (args.flag_zero)
		space = '0';
	if (!args.flag_minus)
		while (args.width > 1)
		{
			ft_putchar(space);
			len++;
			args.width--;
		}
	ft_putchar(*flag);
	while (args.width > 1)
	{
		ft_putchar(space);
		len++;
		args.width--;
	}
	return (len);
}

int		ft_incorrect_flag(va_list *ap, char *flag)
{
	t_arg	args;
	int		value;

	init_args(&args);
	(void)ap;
	while (*flag != '\0')
	{
		ft_verif_flag_flags(&flag, &args);
		ft_verif_has_mod(&flag, &args);
		if (*flag != '\0')
			ft_verif_precision(&flag, &args);
		if (ft_is_special_flag(*flag) && *(flag + 1) == '\0')
			value = ft_compute_incorrect_flag(flag, args);
		flag++;
	}
	return (value);
}

int		compute_wchar_length(wchar_t chr)
{
	if (chr < 0x7F)
		return (1);
	if (chr < 0x7FF)
		return (2);
	if (chr < 0xFFFF)
		return (3);
	return (4);
}
