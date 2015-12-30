#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*f)(void *, size_t))
{
	(*f)(&((*alst)->content), (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
