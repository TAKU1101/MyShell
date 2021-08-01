#include "command_list_units.h"

void	cm_lstclear(t_commands **lst)
{
	t_commands *current;
	t_commands *next;

	if (!lst)
		return ;
	current = cm_lstfirst(*lst);
	while (current)
	{
		next = current->next;
		cm_lstdelone(current);
		current = next;
	}
}
