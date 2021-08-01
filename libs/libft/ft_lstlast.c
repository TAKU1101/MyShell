#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_element;

	last_element = NULL;
	while (lst != NULL)
	{
		if (lst->next == NULL)
		{
			last_element = lst;
			return (last_element);
		}
		lst = lst->next;
	}
	last_element = lst;
	return (last_element);
}
