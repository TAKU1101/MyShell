#include "libft.h"

static int		calc_digits(long long int num)
{
	int		digits;

	if (num == 0)
	{
		return (1);
	}
	digits = 0;
	while (num != 0)
	{
		num /= 10;
		digits++;
	}
	return (digits);
}

static void		ft_reverse(char *str, size_t length)
{
	size_t	start;
	size_t	end;
	char	temp;

	start = 0;
	end = length - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

static char		*input_string(long long int num, char *str,
													int digits, int is_minus)
{
	int				i;
	long long int	temp;

	i = 0;
	while (digits > 0)
	{
		temp = num % 10;
		if (temp < 0)
		{
			temp *= -1;
		}
		str[i] = temp + '0';
		num /= 10;
		digits--;
		i++;
	}
	if (is_minus == 1)
	{
		str[i++] = '-';
	}
	str[i] = '\0';
	return (str);
}

char			*ft_lltoa(long long int num)
{
	char	*result;
	int		digits;
	int		is_minus;

	digits = calc_digits(num);
	is_minus = 0;
	if (num == LLONG_MIN)
	{
		return (ft_strdup("-9223372036854775808"));
	}
	if (num < 0)
	{
		is_minus = 1;
		num *= -1;
	}
	if (!(result = (char *)malloc(sizeof(char) * (digits + is_minus + 1))))
	{
		return (NULL);
	}
	input_string(num, result, digits, is_minus);
	ft_reverse(result, ft_strlen(result));
	return (result);
}
