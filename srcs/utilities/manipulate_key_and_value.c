#include "utilities.h"

char		*extract_key(char *arg)
{
	char	*result;
	int		len_key;

	if (!can_find_equals_sign(arg))
	{
		return (ft_strdup(arg));
	}
	len_key = get_index_equals_sign(arg);
	if (!(result = ft_substr(arg, 0, len_key)))
	{
		return (NULL);
	}
	return (result);
}

int			update_env_value(t_envs *list, char *arg)
{
	t_envs	*current;
	char	*key;
	char	*new_value;

	current = list;
	if (!(key = extract_key(arg)))
		return (ERROR);
	if (!(new_value = ft_strdup(arg + ft_strlen(key) + 1)))
		return (ERROR);
	while (current)
	{
		if (!ft_strcmp(key, current->key))
		{
			free(current->value);
			if (!(current->value = ft_strdup(new_value)))
				return (ERROR);
			current->is_equal_found = TRUE;
			break ;
		}
		current = current->next;
	}
	free_add_null_pointer(key);
	free_add_null_pointer(new_value);
	return (SUCCESS);
}

char		*get_key(t_envs *lst)
{
	char	*result;
	int		len_key;
	int		i;

	if (can_find_equals_sign(lst->key_value_pair))
		lst->is_equal_found = TRUE;
	else
	{
		lst->is_equal_found = FALSE;
		if (!(result = ft_strdup(lst->key_value_pair)))
			return (NULL);
		return (result);
	}
	len_key = get_index_equals_sign(lst->key_value_pair);
	if (!(result = (char *)malloc(sizeof(char) * (len_key + 1))))
		return (NULL);
	i = 0;
	while (i < len_key)
	{
		result[i] = lst->key_value_pair[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char		*get_value(t_envs *lst)
{
	char	*result;
	int		start;
	int		len_value;
	int		i;

	if (!lst->is_equal_found)
	{
		if (!(result = ft_strdup("")))
			return (NULL);
		return (result);
	}
	start = get_index_equals_sign(lst->key_value_pair) + 1;
	len_value = ft_strlen(lst->key_value_pair) - start;
	if (!(result = (char *)malloc(sizeof(char) * (len_value + 1))))
		return (NULL);
	i = 0;
	while (i < len_value)
	{
		result[i] = lst->key_value_pair[start];
		i++;
		start++;
	}
	result[i] = '\0';
	return (result);
}

int			set_key_and_value(t_envs *new)
{
	if (!(new->key = get_key(new)))
	{
		return (ERROR);
	}
	if (!(new->value = get_value(new)))
	{
		return (ERROR);
	}
	return (SUCCESS);
}
