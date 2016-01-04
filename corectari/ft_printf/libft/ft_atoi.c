#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		sgn;
	long	nbr;

	i = 0;
	sgn = 0;
	nbr = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sgn = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr *= 10;
		nbr += str[i] - '0';
		i++;
	}
	if (sgn == 1)
		nbr *= -1;
	return (nbr);
}
