#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	int		ok;

	i = 0;
	ok = 1;
	while (i < n)
	{
		if (ok)
			dst[i] = src[i];
		else
			dst[i] = '\0';
		if (src[i] == '\0')
			ok = 0;
		i++;
	}
	return (dst);
}
