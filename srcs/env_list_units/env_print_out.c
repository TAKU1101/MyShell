#include "env_list_units.h"

void	print_sorted_list(t_envs *list)
{
	if (!list)
	{
		return ;
	}
	while (list)
	{
		if (list->key)
		{
			ft_putstr_fd("declare -x ", STDOUT_FILENO);
			ft_putstr_fd(list->key, STDOUT_FILENO);
			if (!list->is_equal_found)
			{
				write(1, "\n", 1);
			}
			else
			{
				ft_putstr_fd("=", STDOUT_FILENO);
				ft_putstr_fd("\"", STDOUT_FILENO);
				ft_putstr_fd(list->value, STDOUT_FILENO);
				ft_putendl_fd("\"", STDOUT_FILENO);
			}
		}
		list = list->next;
	}
}

int		print_out_envs(t_minishell *shell)
{
	sort_list(&shell->sort_list);
	print_sorted_list(shell->sort_list);
	return (SUCCESS);
}
