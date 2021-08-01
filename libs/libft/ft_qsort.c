#include "libft.h"

void	ft_qsort(int *array, int first, int last)
{
	int i;
	int j;
	int pivot;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;
		while (i < j)
		{
			while (array[i] <= array[pivot] && i < last)
				i++;
			while (array[j] > array[pivot])
				j--;
			if (i < j)
			{
				ft_swap(&array[i], &array[j]);
			}
		}
		ft_swap(&array[pivot], &array[j]);
		ft_qsort(array, first, j - 1);
		ft_qsort(array, j + 1, last);
	}
}
