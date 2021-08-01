#include "env_list_units.h"

void	env_lstclear(t_envs **list)
{
	t_envs	*current;
	t_envs	*next;

	if (!list)
	{
		return ;
	}
	current = *list;
	while (current)
	{
		next = current->next;
		env_lstdelone(current);
		current = next;
	}
}
