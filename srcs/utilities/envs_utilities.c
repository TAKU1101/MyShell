#include "utilities.h"

int			is_env_valid_for_export_use(char *args)
{
	int	i;

	if (ft_isdigit(args[0]))
	{
		return (FALSE);
	}
	if (args[0] == '=')
	{
		return (FALSE);
	}
	i = 0;
	while (args[i] && args[i] != '=')
	{
		if (!(ft_isalnum(args[i]) || args[i] == '_'))
		{
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

int			is_env_valid_for_unset_use(char *args)
{
	int	i;

	if (ft_isdigit(args[0]))
	{
		return (FALSE);
	}
	i = 0;
	while (args[i])
	{
		if (!(ft_isalnum(args[i]) || args[i] == '_'))
		{
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

int			get_index_equals_sign(char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		if (str[index] == '=')
		{
			break ;
		}
		index++;
	}
	return (index);
}

int			can_find_equals_sign(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
		{
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}
