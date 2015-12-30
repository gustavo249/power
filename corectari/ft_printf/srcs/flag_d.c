#include "ft_printf.h"

char	*compute_precision(char *text, t_arg args)
{
	int		minus;
	char	*str0;

	minus = 0;
	text = ft_strrev(text);
	if (text[ft_strlen(text) - 1] == '-')
	{
		minus = 1;
		text[ft_strlen(text) - 1] = '\0';
	}
	if (args.dot_width > ft_strlen(text))
	{
		str0 = ft_memalloc(args.dot_width - ft_strlen(text) + 1);
		str0 = ft_memset(str0, '0', args.dot_width - ft_strlen(text));
		text = ft_strjoin(text, str0);
	}
	if (minus)
		text = ft_strjoin(text, "-");
	text = ft_strrev(text);
	return (text);
}

char	*ft_compute_sign(char *text, t_arg args)
{
	int		minus;

	minus = 0;
	text = ft_strrev(text);
	if (text[ft_strlen(text) - 1] == '-')
		minus = 1;
	if (args.flag_plus && minus == 0)
		text = ft_strjoin(text, "+");
	else if (args.flag_space && minus == 0)
		text = ft_strjoin(text, " ");
	text = ft_strrev(text);
	return (text);
}

char	ft_store_sign(char **text)
{
	char	*aux;
	char	sgn;

	aux = *text;
	sgn = 0;
	if (aux[0] == '-' || aux[0] == '+' || aux[0] == ' ')
	{
		sgn = aux[0];
		aux = ft_strrev(aux);
		aux[ft_strlen(aux) - 1] = '\0';
		aux = ft_strrev(aux);
	}
	if (aux[0] == '0' && aux[1] == 'x')
	{
		sgn = 's';
		aux = ft_strrev(aux);
		aux[ft_strlen(aux) - 2] = '\0';
		aux = ft_strrev(aux);
	}
	*text = aux;
	return (sgn);
}

char	*ft_put_sign_back(char *text, char sgn)
{
	char	*sgn_str;

	if (sgn)
	{
		sgn_str = ft_memalloc(3);
		if (sgn == 's')
		{
			sgn_str[0] = '0';
			sgn_str[1] = 'x';
		}
		else
			sgn_str[0] = sgn;
		text = ft_strjoin(sgn_str, text);
	}
	return (text);
}

char	*ft_compute_width(char *text, t_arg args)
{
	char	*spaces;
	char	chr;
	char	sgn;

	chr = ' ';
	sgn = 0;
	if (args.flag_zero && !args.flag_dot && !args.flag_minus)
		chr = '0';
	if (args.width > ft_strlen(text))
	{
		spaces = ft_memalloc(args.width - ft_strlen(text) + 1);
		spaces = ft_memset(spaces, chr, args.width - ft_strlen(text));
		if (chr == '0')
			sgn = ft_store_sign(&text);
		if (!args.flag_minus)
			text = ft_strjoin(spaces, text);
		else
			text = ft_strjoin(text, spaces);
		if (chr == '0' && sgn)
			text = ft_put_sign_back(text, sgn);
	}
	return (text);
}
