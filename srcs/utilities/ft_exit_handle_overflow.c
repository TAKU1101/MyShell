#include "utilities.h"

UINT		*convert_decimal_to_binary(LLINT num)
{
	UINT	*result;
	int		digit;
	int		one;

	if (!(result = (UINT *)malloc(sizeof(UINT) * (MAX_BIT + 1))))
	{
		return (NULL);
	}
	digit = 0;
	while (digit < MAX_BIT)
	{
		one = (UINT)1 << digit;
		if ((num & one) == 0)
		{
			result[digit] = 0;
		}
		else
		{
			result[digit] = 1;
		}
		digit++;
	}
	return (result);
}

UINT		*create_bit_weight(void)
{
	UINT	*bit_weight;
	int		i;
	int		value;

	if (!(bit_weight = (UINT *)malloc(sizeof(UINT) * EIGHT_BIT)))
	{
		return (NULL);
	}
	i = 0;
	value = 1;
	while (i < EIGHT_BIT)
	{
		bit_weight[i] = value;
		value *= 2;
		i++;
	}
	return (bit_weight);
}

UINT		get_exit_status_from_negative_value(LLINT num)
{
	UINT	result;
	UINT	*binary;
	UINT	*bit_weight;
	int		i;

	if (!(binary = convert_decimal_to_binary(num)))
	{
		return (ERROR);
	}
	if (!(bit_weight = create_bit_weight()))
	{
		return (ERROR);
	}
	i = 0;
	result = 0;
	while (i < 8)
	{
		result += (binary[i] * bit_weight[i]);
		i++;
	}
	unsigned_free_add_null_pointer(binary);
	unsigned_free_add_null_pointer(bit_weight);
	return (result);
}

int			is_overflowing(LLINT num, const char *str)
{
	char	*temp;
	int		is_overflowing;

	if (!(temp = ft_lltoa(num)))
	{
		return (ERROR);
	}
	if (format_string_for_irregular_input(&str) == ERROR)
	{
		return (ERROR);
	}
	if (!ft_strcmp(temp, str))
	{
		is_overflowing = FALSE;
	}
	else
	{
		is_overflowing = TRUE;
	}
	free_add_null_pointer(temp);
	return (is_overflowing);
}
