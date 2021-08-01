#include "bin_list_units.h"

void	bin_lstdelone(t_bins *lst)
{
	if (lst)
	{
		if (lst->path)
		{
			free(lst->path);
			lst->path = NULL;
		}
		if (lst->name)
		{
			free(lst->name);
			lst->name = NULL;
		}
		free(lst);
		lst = NULL;
	}
}
