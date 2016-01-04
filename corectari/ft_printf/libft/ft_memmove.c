#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*aux;

	i = 0;
	aux = (unsigned char*)malloc(sizeof(unsigned char) * (len + 1));
	while (i < len)
	{
		aux[i] = *(unsigned char*)(src + i);
		i++;
	}
	i = 0;
	while (i < len)
	{
		*(unsigned char*)(dst + i) = aux[i];
		i++;
	}
	free(aux);
	return (dst);
}
