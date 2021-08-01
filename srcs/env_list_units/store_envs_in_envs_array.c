#include "env_list_units.h"

static char		*create_key_value_pair(t_envs *current)
{
	char *temp1;
	char *temp2;
	char *result;

	if (!(temp1 = ft_strjoin(current->key, "=")))
	{
		return (NULL);
	}
	if (!(temp2 = ft_strjoin(temp1, current->value)))
	{
		return (NULL);
	}
	free_add_null_pointer(temp1);
	if (!(result = ft_strdup(temp2)))
	{
		return (NULL);
	}
	free_add_null_pointer(temp2);
	return (result);
}

int				store_envs_in_envs_array(t_minishell *shell)
{
	t_envs	*current;
	int		len;
	int		i;

	len = envs_lstsize(shell->envs);
	if (!(shell->envs_array = (char **)malloc(sizeof(char *) * (len + 1))))
	{
		return (ERROR);
	}
	i = 0;
	current = shell->envs;
	while (i < len)
	{
		if (current->is_equal_found)
		{
			if (!(shell->envs_array[i] = create_key_value_pair(current)))
			{
				return (ERROR);
			}
			i++;
		}
		current = current->next;
	}
	shell->envs_array[i] = NULL;
	return (SUCCESS);
}
