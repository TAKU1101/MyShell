#include "execution.h"

int	execute_path(t_minishell *shell, t_commands *cmd)
{
	int	status;

	if (!ft_strchr(cmd->data[0], '/'))
		return (EXIT_FAILURE);
	signal(SIGINT, do_nothing);
	signal(SIGQUIT, do_nothing);
	if ((g_pid = fork()) < 0)
		ft_putendl_fd("fork error", 2);
	else if (g_pid == 0)
	{
		if (execve(cmd->data[0], cmd->data, shell->envs_array) == -1)
		{
			print_non_file_error_msg(cmd->data[0]);
			shell->exit_status = NOT_FOUND_STATUS;
			exit(EXIT_FAILURE);
		}
	}
	wait(&status);
	shell->exit_status = WEXITSTATUS(status);
	if (status == SIGINT)
		cntl_c_signal(status);
	else if (status == VM_SIGQUIT || status == SIGQUIT)
		cntl_backslash_signal(status);
	set_signal();
	return (EXIT_SUCCESS);
}
