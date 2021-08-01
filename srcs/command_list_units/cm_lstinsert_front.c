#include "command_list_units.h"

void	cm_lstinsert_front(t_commands *lst, t_commands *new)
{
	t_commands	*prev;

	if (lst)
	{
		if (new)
		{
			if ((prev = lst->prev))
				prev->next = new;
			lst->prev = new;
			new->prev = prev;
			new->next = lst;
		}
	}
	else
	{
		lst = new;
	}
}
