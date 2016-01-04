#include "ft_printf.h"

void	init_args(t_arg *args)
{
	args->flag_hash = 0;
	args->flag_zero = 0;
	args->flag_plus = 0;
	args->flag_minus = 0;
	args->flag_space = 0;
	args->flag_dot = 0;
	args->flag_wild = 0;
	args->mod_h = 0;
	args->mod_hh = 0;
	args->mod_l = 0;
	args->mod_ll = 0;
	args->mod_j = 0;
	args->mod_z = 0;
	args->width = 0;
	args->dot_width = 0;
}

void	ft_verif_flag_flags(char **flag, t_arg *args)
{
	if (**flag == '#')
		args->flag_hash = 1;
	if (**flag == '0')
		args->flag_zero = 1;
	if (**flag == '-')
		args->flag_minus = 1;
	if (**flag == '+')
		args->flag_plus = 1;
	if (**flag == ' ')
		args->flag_space = 1;
}

void	ft_verif_has_mod(char **flag, t_arg *args)
{
	if (**flag == 'h' && *(*flag + 1) == 'h')
	{
		args->mod_hh = 1;
		(*flag)++;
	}
	else if (**flag == 'l' && *(*flag + 1) == 'l')
	{
		args->mod_ll = 1;
		(*flag)++;
	}
	else if (**flag == 'l')
		args->mod_l = 1;
	else if (**flag == 'h')
		args->mod_h = 1;
	else if (**flag == 'j')
		args->mod_j = 1;
	else if (**flag == 'z')
		args->mod_z = 1;
}

void	ft_verif_precision(char **flag, t_arg *args)
{
	if (ft_isdigit(**flag))
	{
		args->width = 0;
		while (ft_isdigit(**flag))
		{
			args->width = (args->width * 10) + **flag - '0';
			(*flag)++;
		}
		(*flag)--;
	}
	else if (**flag == '.')
	{
		args->flag_dot = 1;
		(*flag)++;
		args->dot_width = 0;
		while (ft_isdigit(**flag))
		{
			args->dot_width = (args->dot_width * 10) + **flag - '0';
			(*flag)++;
		}
		(*flag)--;
	}
}

int		ft_correct_flag(va_list *ap, char *flag, int so_far)
{
	t_arg	args;
	int		value;

	init_args(&args);
	while (*flag != '\0')
	{
		ft_verif_flag_flags(&flag, &args);
		ft_verif_has_mod(&flag, &args);
		ft_verif_wildcard(ap, &flag, &args);
		ft_verif_wildprecision(ap, &flag, &args);
		if (*flag != '0')
			ft_verif_precision(&flag, &args);
		if (ft_strchr(KNOWN_FLAGS, *flag))
			value = ft_compute_flag(ap, flag, args, so_far);
		flag++;
	}
	return (value);
}
