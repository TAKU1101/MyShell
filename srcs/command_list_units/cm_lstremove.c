#include "command_list_units.h"

t_commands	*cm_lstremove(t_commands *current)
{
	t_commands *prev;
	t_commands *next;

	prev = current->prev;
	next = current->next;
	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
	current->prev = NULL;
	current->next = NULL;
	return (current);
}
