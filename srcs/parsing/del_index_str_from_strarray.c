#include "../../includes/parsing.h"

static int	elem_len_count(char **array)
{
	int len;

	len = 0;
	while (array[len])
	{
		len++;
	}
	return (len);
}

static void	char_array_all_free(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char		**del_index_str_from_strarray(char **data, int n)
{
	char	**array;
	int		elem_len;
	int		i;

	elem_len = elem_len_count(data);
	if (!(array = (char **)malloc(sizeof(char *) * elem_len)))
		return (NULL);
	i = 0;
	while (i < n)
	{
		array[i] = ft_strdup(data[i]);
		i++;
	}
	while (data[n + 1])
	{
		array[n] = ft_strdup(data[n + 1]);
		n++;
	}
	array[elem_len - 1] = NULL;
	char_array_all_free(data);
	return (array);
}

char		**delete_strings_with_redirection_signs(char **data, int n)
{
	return (del_index_str_from_strarray(data, n));
}

char		**delete_strings_with_filename(char **data, int n)
{
	return (del_index_str_from_strarray(data, n));
}
