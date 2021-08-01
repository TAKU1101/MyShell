#include "env_list_units.h"

char	*get_env_value(t_minishell *shell, char *key)
{
	t_envs	*current;
	char	*value;

	current = shell->envs;
	value = NULL;
	if (!ft_strcmp("?", key))
	{
		if (!(value = ft_itoa(shell->exit_status)))
			return (NULL);
		return (value);
	}
	while (current)
	{
		if (!ft_strcmp(current->key, key))
		{
			if (!(value = ft_strdup(current->value)))
			{
				return (NULL);
			}
			return (value);
		}
		current = current->next;
	}
	return (NULL);
}
