#include "../../includes/parsing.h"

static int	generate_file(char *data, t_commands *cmd, int type, int n)
{
	int fd;

	free(cmd->output_file[n]);
	cmd->output_file[n] = ft_strdup(data);
	cmd->output_type[n] = type;
	if ((fd = open(cmd->output_file[n], type, S_IREAD | S_IWRITE)) == -1)
		return (EXIT_FAILURE);
	close(fd);
	return (EXIT_SUCCESS);
}

static int	setred(char *arg, int fd[256], int is_use[256], int def)
{
	int n;

	n = ft_atoi(arg);
	if (n >= 256)
	{
		ft_putendl_fd("minishell: Bad file descriptor", 2);
		return (-1);
	}
	if (!n)
		n = def;
	fd[n] = n;
	is_use[n] = TRUE;
	return (n);
}

static int	set_input_file_data(char *data, t_commands *cmd, \
												t_minishell *shell, int n)
{
	int fd;

	free(cmd->input_file[n]);
	if (!(cmd->input_file[n] = ft_strdup(data)))
		return (EXIT_FAILURE);
	if ((fd = open(cmd->input_file[n], O_RDONLY)) == -1)
	{
		print_non_file_error_msg(cmd->input_file[n]);
		shell->exit_status = EXIT_FAILURE;
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int			set_file_data(char **data, int i, t_commands *cmd, \
												t_minishell *shell)
{
	int n;

	if (is_redirection(data[i], ">"))
	{
		if ((n = setred(data[i], cmd->output_fd, cmd->output_is_use, 1)) == -1)
			return (EXIT_FAILURE);
		if (generate_file(data[i + 1], cmd, O_WRONLY | O_CREAT | O_TRUNC, n))
			return (EXIT_FAILURE);
	}
	else if (is_redirection(data[i], ">>"))
	{
		if ((n = setred(data[i], cmd->output_fd, cmd->output_is_use, 1)) == -1)
			return (EXIT_FAILURE);
		if (generate_file(data[i + 1], cmd, O_WRONLY | O_CREAT | O_APPEND, n))
			return (EXIT_FAILURE);
	}
	else if (is_redirection(data[i], "<"))
	{
		if ((n = setred(data[i], cmd->input_fd, cmd->input_is_use, 0)) == -1)
			return (EXIT_FAILURE);
		if (set_input_file_data(data[i + 1], cmd, shell, n))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
