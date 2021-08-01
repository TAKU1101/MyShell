#include "execution.h"

t_commands	*get_elem_after_nth(t_commands *cmd, int n)
{
	t_commands	*current;
	int			i;

	i = 0;
	current = cmd;
	while (current && i < n)
	{
		i++;
		current = current->next;
	}
	return (current);
}
