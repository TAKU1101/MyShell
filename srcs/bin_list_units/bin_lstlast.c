#include "bin_list_units.h"

t_bins	*bin_lstlast(t_bins *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
