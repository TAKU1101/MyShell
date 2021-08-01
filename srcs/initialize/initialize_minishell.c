#include "initialize.h"

int		initialize_minishell(t_minishell *shell, char **envp)
{
	shell->cmd = NULL;
	shell->exit_status = 0;
	shell->envs = NULL;
	shell->sort_list = NULL;
	shell->envs_array = NULL;
	if (initialize_env_lst(shell, envp) == ERROR)
	{
		return (ERROR);
	}
	if (store_envs_in_envs_array(shell) == ERROR)
	{
		return (ERROR);
	}
	if (initialize_bins(shell) == EXIT_FAILURE)
	{
		return (ERROR);
	}
	return (SUCCESS);
}
