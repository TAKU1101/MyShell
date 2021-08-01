#include "../../includes/parsing.h"

int			is_redirection(char *haystack, char *needle)
{
	char	*tmp;
	int		i;

	tmp = ft_strnstr(haystack, needle, ft_strlen(haystack));
	if (!tmp || !*tmp)
		return (FALSE);
	i = 0;
	while (ft_isdigit(haystack[i]))
		i++;
	i += ft_strlen(needle);
	if (i == (int)ft_strlen(haystack))
		return (TRUE);
	return (FALSE);
}
