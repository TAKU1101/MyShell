#include "command_list_units.h"

t_commands	*cm_lstlast(t_commands *lst)
{
	t_commands	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while (lst->next)
	{
		lst = lst->next;
	}
	last = lst;
	return (last);
}
