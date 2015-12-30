#include "libft.h"

void	ft_lstdel(t_list **alst, void (*f)(void *, size_t))
{
	if ((*alst)->next)
		ft_lstdel(&((*alst)->next), f);
	(*f)(&((*alst)->content), (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
