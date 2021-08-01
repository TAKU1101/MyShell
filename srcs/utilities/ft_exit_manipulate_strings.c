#include "utilities.h"

int			modify_string_with_minus(const char **str)
{
	char *temp;
	char *result;

	temp = NULL;
	result = NULL;
	if (ft_strncmp(*str, "-0", 2))
	{
		return (SUCCESS);
	}
	if (!(temp = ft_strdup("-")))
		return (ERROR);
	(*str)++;
	while (**str == '0')
	{
		(*str)++;
	}
	if (!(result = ft_strjoin(temp, *str)))
		return (ERROR);
	*str = result;
	free_add_null_pointer(temp);
	return (SUCCESS);
}

int			format_string_for_irregular_input(const char **str)
{
	if (**str == '+')
	{
		(*str)++;
	}
	if (!ft_strcmp(*str, "-0"))
	{
		(*str)++;
	}
	if (**str == '-')
	{
		if (modify_string_with_minus(str) == ERROR)
			return (ERROR);
	}
	if (!ft_strcmp(*str, "0"))
	{
		return (SUCCESS);
	}
	while (*(*str + 1) != '\0' && **str == '0')
	{
		(*str)++;
	}
	return (SUCCESS);
}
