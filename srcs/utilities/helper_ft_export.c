#include "utilities.h"

int		is_argv_empty_string(char *target)
{
	if (target[0] == '\0')
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

void	handle_error_case(char *args, int *temp_status)
{
	print_error_ft_export(args);
	*temp_status = ERROR;
}
