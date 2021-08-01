#include "env_list_units.h"

int			initialize_env_lst(t_minishell *minishell, char **envp)
{
	t_envs	*env;
	t_envs	*new;
	int		i;

	if (*envp == NULL)
	{
		return (SUCCESS);
	}
	if (!(env = env_lstnew(ft_strdup(envp[0]))))
		return (ERROR);
	minishell->envs = env;
	minishell->sort_list = env;
	i = 1;
	while (envp[i])
	{
		if (!(new = env_lstnew(ft_strdup(envp[i]))))
		{
			return (ERROR);
		}
		env->is_equal_found = TRUE;
		env->next = new;
		env = new;
		i++;
	}
	return (SUCCESS);
}

int			initialize_sort_list(t_minishell *minishell, char *arg)
{
	t_envs	*env;

	if (!(env = env_lstnew(ft_strdup(arg))))
	{
		return (ERROR);
	}
	minishell->envs = env;
	minishell->sort_list = env;
	return (SUCCESS);
}
