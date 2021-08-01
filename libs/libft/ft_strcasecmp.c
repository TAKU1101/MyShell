#include "libft.h"

int				ft_strcasecmp(const char *str1, const char *str2)
{
	int i;
	int diff;

	i = 0;
	while (str1[i] || str2[i])
	{
		diff = ft_tolower((unsigned char)str1[i]) -
											ft_tolower((unsigned char)str2[i]);
		if (diff != 0)
		{
			return (diff);
		}
		i++;
	}
	return (0);
}
