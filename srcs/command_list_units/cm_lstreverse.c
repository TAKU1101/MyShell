#include "command_list_units.h"

void		cm_lstreverse(t_commands *start, t_commands *end)
{
	t_commands	*tmp;

	while (start != end && start->prev != end)
	{
		cm_lstswap(start, end);
		tmp = start;
		start = end;
		end = tmp;
		start = start->next;
		end = end->prev;
	}
}
