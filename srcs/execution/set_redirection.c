#include "execution.h"

static int	dup_redirection(char *name, int now, int type, int *backup)
{
	int	fd;

	if (name)
	{
		if ((fd = open(name, type)) == -1)
			return (EXIT_FAILURE);
		if ((*backup = dup(now)) == -1)
			return (EXIT_FAILURE);
		if ((dup2(fd, now)) == -1)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int			set_redirection(t_commands *cmd, int input_fd_backup[256], \
													int output_fd_backup[256])
{
	int i;

	i = 0;
	while (i < 256)
	{
		if (cmd->input_is_use[i])
			if (dup_redirection(cmd->input_file[i], cmd->input_fd[i], \
											O_RDONLY, &(input_fd_backup[i])))
				return (EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (i < 256)
	{
		if (cmd->output_is_use[i])
			if (dup_redirection(cmd->output_file[i], cmd->output_fd[i], \
								cmd->output_type[i], &(output_fd_backup[i])))
				return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	reset_input_redirection(t_commands *cmd, int input_fd_backup[256])
{
	int i;

	i = 0;
	while (i < 256)
	{
		if (cmd->input_is_use[i])
		{
			if (cmd->input_file[i])
			{
				if (dup2(input_fd_backup[i], cmd->input_fd[i]) == -1)
					return (EXIT_FAILURE);
				if (close(input_fd_backup[i]) == -1)
					return (EXIT_FAILURE);
			}
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	reset_output_redirection(t_commands *cmd, int output_fd_backup[256])
{
	int i;

	i = 0;
	while (i < 256)
	{
		if (cmd->output_is_use[i])
		{
			if (cmd->output_file[i])
			{
				if (dup2(output_fd_backup[i], cmd->output_fd[i]) == -1)
					return (EXIT_FAILURE);
				if (close(output_fd_backup[i]) == -1)
					return (EXIT_FAILURE);
			}
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int			reset_redirection(t_commands *cmd, int input_fd_backup[256], \
													int output_fd_backup[256])
{
	if (reset_input_redirection(cmd, input_fd_backup))
		return (EXIT_FAILURE);
	if (reset_output_redirection(cmd, output_fd_backup))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
