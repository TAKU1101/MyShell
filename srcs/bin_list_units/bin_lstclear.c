#include "bin_list_units.h"

void	bin_lstclear(t_bins **lst)
{
	t_bins	*current;
	t_bins	*next;

	if (!lst)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		bin_lstdelone(current);
		current = next;
	}
}
