#include "../../includes/parsing.h"

int		del_index_char_from_str(char *str, int n)
{
	int len;

	len = ft_strlen(str);
	if (len < n)
		return (1);
	ft_memmove(&str[n], &str[n + 1], len - n);
	return (0);
}
