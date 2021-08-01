#include "builtins.h"

int	ft_pwd(void)
{
	char current_dir[PATH_MAX];

	if (!getcwd(current_dir, PATH_MAX))
	{
		return (ERROR);
	}
	ft_putendl_fd(current_dir, 1);
	return (SUCCESS);
}
