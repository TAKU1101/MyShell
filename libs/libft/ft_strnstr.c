#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		if (haystack[i + j] == needle[j])
		{
			while (needle[j] != '\0')
			{
				if (haystack[i + j] != needle[j])
					break ;
				j++;
			}
			if (j == ft_strlen(needle) && i + j <= len)
			{
				return ((char *)haystack + i);
			}
		}
		i++;
	}
	return (NULL);
}
