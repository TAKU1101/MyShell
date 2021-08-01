#include "utilities.h"

void		free_2d_array(char **contents)
{
	int	i;

	i = 0;
	while (contents[i])
	{
		free(contents[i]);
		i++;
	}
	free(contents);
}

void		free_add_null_pointer(char *str)
{
	free(str);
	str = NULL;
}

void		unsigned_free_add_null_pointer(unsigned int *array)
{
	free(array);
	array = NULL;
}
