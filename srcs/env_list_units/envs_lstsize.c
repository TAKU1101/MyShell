#include "env_list_units.h"

int		envs_lstsize(t_envs *list)
{
	int len;

	len = 0;
	while (list)
	{
		if (list->is_equal_found)
		{
			len++;
		}
		list = list->next;
	}
	return (len);
}
