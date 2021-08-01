#include "env_list_units.h"

void	env_lstdelone(t_envs *lst)
{
	if (lst)
	{
		free(lst->key_value_pair);
		lst->key_value_pair = NULL;
		free(lst->key);
		lst->key = NULL;
		free(lst->value);
		lst->value = NULL;
		free(lst);
	}
}
