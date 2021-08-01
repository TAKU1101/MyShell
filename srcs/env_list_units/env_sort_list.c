#include "env_list_units.h"

#define START_VALUE 1

void		swap_element(char **first, char **second)
{
	char *temp;

	temp = *first;
	*first = *second;
	*second = temp;
}

void		swap_node(t_envs **first, t_envs **second)
{
	swap_element(&(*first)->key_value_pair, &(*second)->key_value_pair);
	swap_element(&(*first)->key, &(*second)->key);
	swap_element(&(*first)->value, &(*second)->value);
	ft_swap(&(*first)->is_equal_found, &(*second)->is_equal_found);
}

int			should_swap(char *first, char *second)
{
	if (ft_strcmp(first, second) > 0)
	{
		return (TRUE);
	}
	return (FALSE);
}

void		sort_list(t_envs **sort_list)
{
	int		did_swap;
	t_envs	*current;
	t_envs	*next;

	if (!(*sort_list))
		return ;
	next = NULL;
	while (TRUE)
	{
		current = *sort_list;
		did_swap = FALSE;
		while (current->next != next)
		{
			if (should_swap(current->key, current->next->key))
			{
				swap_node(&current, &current->next);
				did_swap = TRUE;
			}
			current = current->next;
		}
		if (did_swap == FALSE)
			return ;
		next = current;
	}
}
