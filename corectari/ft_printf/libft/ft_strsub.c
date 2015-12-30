#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	start_s;
	char	*new;

	start_s = start;
	new = (char*)malloc(sizeof(char) * (len + 1));
	if (new)
	{
		i = 0;
		while (i < len)
		{
			new[i] = s[i + start_s];
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}
