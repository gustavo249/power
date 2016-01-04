#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	aux;

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		aux = i;
		while (s1[aux] != '\0' && s2[j] != '\0' && s1[aux] == s2[j] && aux < n)
		{
			aux++;
			j++;
		}
		if (s2[j] == '\0')
			return (char*)(s1 + i);
		i++;
	}
	return (NULL);
}
