#include "minishell.h"

int	is_all_space(char *str)
{
	while (*str)
	{
		if (' ' != *str)
			return (FALSE);
		str++;
	}
	return (TRUE);
}
