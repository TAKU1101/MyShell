#include "execution.h"

static int	execute_bin_init(t_minishell *shell, t_commands *cmd, char **path)
{
	if (ft_strchr(cmd->data[0], '/'))
		return (EXIT_FAILURE);
	if ((*path = get_bin_path(shell, cmd->data[0])) == NULL)
	{
		print_non_command_error_msg(cmd->data[0]);
		shell->exit_status = NOT_FOUND_STATUS;
		return (EXIT_FAILURE);
	}
	signal(SIGINT, do_nothing);
	signal(SIGQUIT, do_nothing);
	return (EXIT_SUCCESS);
}

int			execute_bin(t_minishell *shell, t_commands *cmd)
{
	char	*path;
	int		status;

	if (execute_bin_init(shell, cmd, &path))
		return (EXIT_FAILURE);
	if ((g_pid = fork()) < 0)
		ft_putendl_fd("fork error", 2);
	else if (g_pid == 0)
	{
		if (execve(path, cmd->data, shell->envs_array) == -1)
		{
			print_non_file_error_msg(path);
			free_add_null_pointer(path);
			exit(EXIT_FAILURE);
		}
	}
	wait(&status);
	shell->exit_status = WEXITSTATUS(status);
	free_add_null_pointer(path);
	if (status == SIGINT)
		cntl_c_signal(status);
	else if (status == VM_SIGQUIT || status == SIGQUIT)
		cntl_backslash_signal(status);
	set_signal();
	return (EXIT_SUCCESS);
}
