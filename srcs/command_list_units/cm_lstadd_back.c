#include "command_list_units.h"

void	cm_lstadd_back(t_commands **lst, t_commands *new)
{
	t_commands *last;

	if (*lst)
	{
		if (new)
		{
			last = cm_lstlast(*lst);
			last->next = new;
			new->prev = last;
			new->next = NULL;
		}
	}
	else
	{
		*lst = new;
	}
}
