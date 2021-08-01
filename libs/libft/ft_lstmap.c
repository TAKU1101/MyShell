#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;

	if ((*f) == NULL || (*del) == NULL)
	{
		return (NULL);
	}
	new_list = NULL;
	while (lst != NULL)
	{
	}
	return (new_list);
}
