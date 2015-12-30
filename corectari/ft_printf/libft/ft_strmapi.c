#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*new;

	new = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (new)
	{
		i = 0;
		while (s[i] != '\0')
		{
			new[i] = (*f)(i, s[i]);
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}
