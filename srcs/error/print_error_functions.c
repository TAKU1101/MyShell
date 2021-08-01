#include "error.h"

void	print_error_ft_cd(char *pathname)
{
	ft_putstr_fd("cd: ", STDERR_FILENO);
	ft_putstr_fd(pathname, STDERR_FILENO);
	ft_putendl_fd(": no such file or directory", STDERR_FILENO);
}

void	print_error_ft_export(char *args)
{
	ft_putstr_fd("export: `", STDERR_FILENO);
	ft_putstr_fd(args, STDERR_FILENO);
	ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
}

void	print_error_ft_unset(char *args)
{
	ft_putstr_fd("unset: `", STDERR_FILENO);
	ft_putstr_fd(args, STDERR_FILENO);
	ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
}

int		print_error_ft_exit(int type, char *command)
{
	if (type == TOO_MANY_ARGUMENTS)
	{
		(void)command;
		ft_putendl_fd("exit: too many arguments", STDERR_FILENO);
	}
	else if (type == NUMERIC_ARGUMENT_REQUIRED)
	{
		ft_putstr_fd("exit: ", STDERR_FILENO);
		ft_putstr_fd(command, STDERR_FILENO);
		ft_putendl_fd(": numeric argument required", STDERR_FILENO);
	}
	else if (type == ARG_OVERFLOWING)
	{
		ft_putstr_fd("exit: ", STDERR_FILENO);
		ft_putstr_fd(command, STDERR_FILENO);
		ft_putendl_fd(": numeric argument required", STDERR_FILENO);
	}
	return (ERROR);
}
