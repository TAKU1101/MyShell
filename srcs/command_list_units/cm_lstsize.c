#include "command_list_units.h"

int	cm_lstsize(t_commands *lst)
{
	t_commands	*current;
	int			len;

	len = 0;
	current = cm_lstfirst(lst);
	while (current)
	{
		current = current->next;
		len++;
	}
	return (len);
}
