#include "command_list_units.h"

t_commands	*cm_lstfirst(t_commands *lst)
{
	t_commands	*first;

	if (!lst)
		return (NULL);
	first = lst;
	while (lst->prev)
	{
		lst = lst->prev;
	}
	first = lst;
	return (first);
}
