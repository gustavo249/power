#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*new_content;

	new = (t_list*)malloc(sizeof(t_list));
	if (new)
	{
		new->next = NULL;
		new_content = (void*)malloc(sizeof(void));
		new_content = (void*)content;
		new->content = new_content;
		if (content)
			new->content_size = content_size;
		else
			new->content_size = 0;
	}
	return (new);
}
