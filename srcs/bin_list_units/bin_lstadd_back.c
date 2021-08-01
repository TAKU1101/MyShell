#include "bin_list_units.h"

void	bin_lstadd_back(t_bins **lst, t_bins *new)
{
	t_bins	*last;

	if (*lst)
	{
		if (new)
		{
			last = bin_lstlast(*lst);
			last->next = new;
		}
	}
	else
	{
		*lst = new;
	}
}
