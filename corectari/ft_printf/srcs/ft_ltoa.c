#include "ft_printf.h"

char	*ft_ltoa_base(long number, int base)
{
	static char	buf[32] = "0";
	int			i;

	i = 30;
	if (number == 0)
		return (ft_strdup("0"));
	while (number > 0 && i > 0)
	{
		buf[i] = "0123456789abcdef"[number % base];
		number = number / base;
		--i;
	}
	return (buf + i + 1);
}
