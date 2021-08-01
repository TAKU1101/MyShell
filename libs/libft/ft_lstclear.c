#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_one;

	if (lst == NULL || (*del) == NULL)
	{
		return ;
	}
	while (*lst != NULL)
	{
		next_one = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next_one;
	}
}
