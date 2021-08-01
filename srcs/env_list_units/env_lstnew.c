#include "env_list_units.h"

t_envs			*env_lstnew(char *value)
{
	t_envs	*new;

	new = (t_envs *)malloc(sizeof(t_envs));
	if (!new)
	{
		return (NULL);
	}
	new->key_value_pair = value;
	if (set_key_and_value(new) == ERROR)
	{
		return (NULL);
	}
	new->next = NULL;
	return (new);
}
