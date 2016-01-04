#include "ft_printf.h"

unsigned int	ft_strwlen(wchar_t *str)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (str[i] != '\0')
	{
		len += compute_wchar_length(str[i]);
		i++;
	}
	return (len);
}

void			ft_putwstr(wchar_t *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putwchar(str[i]);
		i++;
	}
}

wchar_t			*ft_strwsub(wchar_t *str, unsigned int start, unsigned int len)
{
	size_t			i;
	wchar_t			*new;
	unsigned int	actual;

	actual = 0;
	new = ft_memalloc(sizeof(wchar_t) * (len + 1));
	if (new)
	{
		i = 0;
		while (actual + compute_wchar_length(str[i + start]) <= len)
		{
			new[i] = str[i + start];
			actual += compute_wchar_length(new[i]);
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}

int				ft_putwstr_width(wchar_t *text, char *spaces, t_arg args)
{
	if (args.flag_minus == 0)
	{
		ft_putstr(spaces);
		ft_putwstr(text);
		return (ft_strlen(spaces) + ft_strwlen(text));
	}
	else
	{
		ft_putwstr(text);
		ft_putstr(spaces);
		return (ft_strlen(spaces) + ft_strwlen(text));
	}
}

int				compute_bigs_flag(va_list *ap, t_arg args)
{
	wchar_t		*text;
	char		*spaces;
	char		ch;

	text = va_arg(*ap, wchar_t *);
	ch = ' ';
	if (args.flag_zero)
		ch = '0';
	if (!text)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (args.flag_dot && args.dot_width < ft_strwlen(text))
		text = ft_strwsub(text, 0, args.dot_width);
	if (args.width > ft_strwlen(text))
	{
		spaces = ft_memalloc(args.width - ft_strwlen(text) + 1);
		spaces = ft_memset(spaces, ch, args.width - ft_strwlen(text));
		return (ft_putwstr_width(text, spaces, args));
	}
	ft_putwstr(text);
	return (ft_strwlen(text));
}
