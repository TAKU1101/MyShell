#include "command_list_units.h"

t_commands	*cm_lstnew(char *commnad_line)
{
	t_commands	*new;

	if (!(new = (t_commands *)malloc(sizeof(t_commands))))
		return (NULL);
	new->command_line = commnad_line;
	cm_lstinit(new);
	return (new);
}
