#include "libft.h"

void	ft_bubblesort(int *array, int upto)
{
	int		i;
	int		j;

	i = 0;
	while (i < upto - 1)
	{
		j = 0;
		while (j < upto - 1 - i)
		{
			if (array[j] > array[j + 1])
			{
				ft_swap(&array[j], &array[j + 1]);
			}
			j++;
		}
		i++;
	}
}
