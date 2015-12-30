#include "ft_printf.h"

int		compute_s_flag(va_list *ap, t_arg args)
{
	char	*text;
	char	*spaces;
	char	ch;

	text = va_arg(*ap, char *);
	ch = ' ';
	if (args.flag_zero)
		ch = '0';
	if (!text)
		text = ft_strdup("(null)");
	if (args.flag_dot && args.dot_width < ft_strlen(text))
		text = ft_strsub(text, 0, args.dot_width);
	if ((args.flag_dot || args.flag_wild) && args.dot_width == 0)
		text = ft_strdup("");
	if (args.width > ft_strlen(text))
	{
		spaces = ft_memalloc(args.width - ft_strlen(text) + 1);
		spaces = ft_memset(spaces, ch, args.width - ft_strlen(text));
		if (args.flag_minus == 0)
			text = ft_strjoin(spaces, text);
		else
			text = ft_strjoin(text, spaces);
	}
	ft_putstr(text);
	return (ft_strlen(text));
}
