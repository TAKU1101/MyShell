#include "minishell.h"

int	any_flag(int flags[])
{
	return (flags[SINGLE] || flags[DOUBLE] || flags[BACKSH]);
	(void)flags;
}
