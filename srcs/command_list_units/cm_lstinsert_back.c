#include "command_list_units.h"

void	cm_lstinsert_back(t_commands *lst, t_commands *new)
{
	t_commands	*next;

	if (lst)
	{
		if (new)
		{
			if ((next = lst->next))
				next->prev = new;
			lst->next = new;
			new->prev = lst;
			new->next = next;
		}
	}
	else
	{
		lst = new;
	}
}
