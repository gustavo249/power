#include "ft_printf.h"

void	ft_next_printf(va_list *ap, char *flag, int *value)
{
	int		len;

	len = ft_strlen(flag);
	if (len > 1 && flag[0] == '%' && ft_is_special_flag(flag[len - 1]))
	{
		*value += ft_incorrect_flag(ap, flag);
	}
	else if (ft_strchr(KNOWN_FLAGS, flag[len - 1]))
	{
		*value += ft_correct_flag(ap, flag, *value);
	}
}

int		ft_findendflag(const char *str)
{
	int		i;

	i = 1;
	if (str[i] == '\0')
		return (0);
	while (ft_strchr(INNER_FLAGS, str[i]))
		i++;
	if (ft_strchr(KNOWN_FLAGS, str[i]))
		return (i);
	else if (ft_is_special_flag(str[i]))
		return (i);
	else
		return (i - 1);
}

int		ft_inner_printf(va_list *ap, const char *format)
{
	int		end;
	char	*flag;
	int		value;

	value = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			end = ft_findendflag(format);
			flag = ft_strsub(format, 0, end + 1);
			ft_next_printf(ap, flag, &value);
			format += end;
		}
		else
		{
			ft_putchar(*format);
			value++;
		}
		format++;
	}
	return (value);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		value;

	va_start(ap, format);
	value = ft_inner_printf(&ap, format);
	va_end(ap);
	return (value);
}
