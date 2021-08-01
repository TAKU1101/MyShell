#include "env_list_units.h"

int		create_pwd(t_minishell *shell, char *current_dir)
{
	t_envs	*new;
	t_envs	*current;

	if (!(new = (t_envs *)malloc(sizeof(t_envs))))
		return (ERROR);
	if (!(new->key_value_pair = ft_strjoin("PWD=", current_dir)))
		return (ERROR);
	if (set_key_and_value(new) == ERROR)
	{
		return (ERROR);
	}
	new->next = NULL;
	if (!shell->envs)
	{
		initialize_sort_list(shell, new->key_value_pair);
		return (SUCCESS);
	}
	current = shell->envs;
	while (current && current->next)
	{
		current = current->next;
	}
	current->next = new;
	return (SUCCESS);
}

int		update_pwd(t_minishell *shell)
{
	char	current_dir[PATH_MAX];
	t_envs	*current;

	if (!getcwd(current_dir, PATH_MAX))
		return (ERROR);
	current = shell->envs;
	while (current)
	{
		if (!ft_strcmp(current->key, "PWD"))
		{
			free(current->value);
			if (!(current->value = ft_strdup(current_dir)))
			{
				return (ERROR);
			}
			return (SUCCESS);
		}
		current = current->next;
	}
	if (create_pwd(shell, current_dir) == ERROR)
	{
		return (ERROR);
	}
	return (SUCCESS);
}

int		create_oldpwd(t_minishell *shell, char *current_dir)
{
	t_envs	*new;
	t_envs	*current;

	if (!(new = (t_envs *)malloc(sizeof(t_envs))))
		return (ERROR);
	if (!(new->key_value_pair = ft_strjoin("OLDPWD=", current_dir)))
		return (ERROR);
	if (set_key_and_value(new) == ERROR)
	{
		return (ERROR);
	}
	new->next = NULL;
	if (!shell->envs)
	{
		initialize_sort_list(shell, new->key_value_pair);
		return (SUCCESS);
	}
	current = shell->envs;
	while (current && current->next)
	{
		current = current->next;
	}
	current->next = new;
	return (SUCCESS);
}

int		update_oldpwd(t_minishell *shell)
{
	char	current_dir[PATH_MAX];
	t_envs	*current;

	if (!getcwd(current_dir, PATH_MAX))
		return (ERROR);
	current = shell->envs;
	while (current)
	{
		if (!ft_strcmp(current->key, "OLDPWD"))
		{
			free(current->value);
			if (!(current->value = ft_strdup(current_dir)))
			{
				return (ERROR);
			}
			return (SUCCESS);
		}
		current = current->next;
	}
	if (create_oldpwd(shell, current_dir) == ERROR)
	{
		return (ERROR);
	}
	return (SUCCESS);
}
