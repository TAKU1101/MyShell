#include "error.h"

void	print_error_cannnot_open_file(char *filename)
{
	ft_putstr_fd(filename, STDERR_FILENO);
	ft_putstr_fd(": cannot open `", STDERR_FILENO);
	ft_putstr_fd(filename, STDERR_FILENO);
	ft_putendl_fd("' (No such file or directory)", STDERR_FILENO);
}
