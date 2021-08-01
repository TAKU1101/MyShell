#include "libft.h"

long long int		ft_atoll(const char *str)
{
	long long int	result;
	int				i;
	int				is_minus;

	if (str == NULL)
		return (0);
	is_minus = FALSE;
	result = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		is_minus = (str[i] == '-') ? TRUE : FALSE;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (is_minus == TRUE)
		result *= -1;
	return (result);
}
