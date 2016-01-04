#include "libft.h"

int		ft_gcd(int a, int b)
{
	if (!b)
		return (a);
	return (ft_gcd(b, a % b));
}
