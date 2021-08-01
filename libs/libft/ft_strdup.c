#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	int		i;

	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!result)
	{
		return (NULL);
	}
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
