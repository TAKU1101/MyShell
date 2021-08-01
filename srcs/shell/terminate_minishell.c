#include "minishell.h"

void		terminate_minishell(t_minishell *minishell)
{
	bin_lstclear(&(minishell->bins));
	cm_lstclear(&(minishell->cmd));
	env_lstclear(&(minishell->envs));
	env_lstclear(&(minishell->sort_list));
	free_2d_array(minishell->envs_array);
}
