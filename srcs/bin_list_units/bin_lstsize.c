#include "bin_list_units.h"

int	bin_lstsize(t_bins *lst)
{
	int		len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
