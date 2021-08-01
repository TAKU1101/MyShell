#include "builtins.h"

static int		add_new_env(t_envs *list, char *args)
{
	t_envs *new;

	if (!(new = (t_envs *)malloc(sizeof(t_envs))))
	{
		return (ERROR);
	}
	if (!(new->key_value_pair = ft_strdup(args)))
	{
		return (ERROR);
	}
	if (set_key_and_value(new) == ERROR)
	{
		return (ERROR);
	}
	new->next = NULL;
	while (list && list->next)
	{
		list = list->next;
	}
	list->next = new;
	return (SUCCESS);
}

static int		is_env_key_in_list(t_minishell *shell, char *arg)
{
	t_envs	*current;
	char	*key;
	int		is_key_found;

	current = shell->sort_list;
	if (!(key = extract_key(arg)))
	{
		return (ERROR);
	}
	is_key_found = FALSE;
	while (current)
	{
		if (!ft_strcmp(key, current->key))
		{
			is_key_found = TRUE;
			break ;
		}
		current = current->next;
	}
	free_add_null_pointer(key);
	return (is_key_found);
}

static int		update_envs_in_list(t_minishell *shell, char *args)
{
	if (!can_find_equals_sign(args))
	{
		return (SUCCESS);
	}
	if (update_env_value(shell->sort_list, args) == ERROR)
	{
		return (ERROR);
	}
	return (SUCCESS);
}

static int		handle_ok_case(t_minishell *shell, char *args)
{
	int temp_status;

	temp_status = SUCCESS;
	if (is_argv_empty_string(args))
	{
		temp_status = SUCCESS;
	}
	else if (!shell->sort_list)
	{
		temp_status = initialize_sort_list(shell, args);
	}
	else if (is_env_key_in_list(shell, args))
	{
		temp_status = update_envs_in_list(shell, args);
	}
	else
	{
		temp_status = add_new_env(shell->sort_list, args);
	}
	return (temp_status);
}

int				ft_export(t_minishell *shell, char **argv)
{
	int temp_status;

	temp_status = 0;
	if (!argv[1])
		return (print_out_envs(shell));
	while (*(++argv))
	{
		if (is_env_valid_for_export_use(*argv) == FALSE)
		{
			handle_error_case(*argv, &temp_status);
			continue ;
		}
		if ((temp_status = handle_ok_case(shell, *argv)) == ERROR)
		{
			return (ERROR);
		}
	}
	return (temp_status);
}
