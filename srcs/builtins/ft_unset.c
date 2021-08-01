#include "builtins.h"

static void			delete_head_node(t_minishell *shell, t_envs *current)
{
	t_envs *next;

	next = current->next;
	env_lstdelone(current);
	shell->sort_list = next;
	shell->envs = next;
}

static void			delete_node(t_envs *current, char *target)
{
	t_envs	*node_after_next;

	while (current && current->next)
	{
		if (!ft_strcmp(target, current->next->key))
		{
			node_after_next = current->next->next;
			env_lstdelone(current->next);
			current->next = node_after_next;
			return ;
		}
		current = current->next;
	}
}

static	void		hanlde_error_case(char *args, int *temp_status, int *i)
{
	print_error_ft_unset(args);
	*temp_status = ERROR;
	(*i)++;
}

int					ft_unset(t_minishell *shell, char **argv)
{
	t_envs	*current;
	int		temp_status;
	int		i;

	temp_status = SUCCESS;
	i = 1;
	while (argv[i])
	{
		if (is_env_valid_for_unset_use(argv[i]) == FALSE)
		{
			hanlde_error_case(argv[i], &temp_status, &i);
			continue ;
		}
		if (!shell->sort_list)
			return (SUCCESS);
		current = shell->sort_list;
		if (!ft_strcmp(argv[i], current->key))
			delete_head_node(shell, current);
		else
			delete_node(current, argv[i]);
		temp_status = SUCCESS;
		i++;
	}
	return (temp_status);
}
