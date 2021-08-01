#include "error.h"

void	print_error_command_not_found(char *command)
{
	ft_putstr_fd(command, STDERR_FILENO);
	ft_putendl_fd(": command not found", STDERR_FILENO);
}
