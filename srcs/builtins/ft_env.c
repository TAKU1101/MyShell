#include "builtins.h"

int		ft_env(t_envs *envs)
{
	if (!envs)
	{
		return (ERROR);
	}
	while (envs)
	{
		if (envs->is_equal_found)
		{
			ft_putstr_fd(envs->key, STDOUT_FILENO);
			ft_putstr_fd("=", STDOUT_FILENO);
			ft_putendl_fd(envs->value, STDOUT_FILENO);
		}
		envs = envs->next;
	}
	return (SUCCESS);
}
