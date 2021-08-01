#include "command_list_units.h"

void	cm_lstadd_front(t_commands **lst, t_commands *new)
{
	t_commands *front;

	if (*lst)
	{
		if (new)
		{
			front = cm_lstfirst(*lst);
			front->prev = new;
			new->next = front;
			new->prev = NULL;
		}
	}
	else
	{
		*lst = new;
	}
}
