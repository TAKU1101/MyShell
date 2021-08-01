#include "builtins.h"

static int		count_argc(char **argv)
{
	int len;

	len = 0;
	while (argv[len])
	{
		len++;
	}
	return (len);
}

static int		is_arg_numeric(char *arg)
{
	int i;

	i = 0;
	if (arg[0] == '-' || arg[0] == '+')
	{
		i = 1;
	}
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
		{
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

static void		skip_spaces(char **args)
{
	while (ft_isspace(**args))
	{
		(*args)++;
	}
}

static void		store_exit_status(t_minishell *shell, LLINT num)
{
	if (num < 0)
	{
		shell->exit_status = get_exit_status_from_negative_value(num);
	}
	else if (0 <= num && num < 256)
	{
		shell->exit_status = num;
	}
	else
	{
		shell->exit_status = num % 256;
	}
}

int				ft_exit(t_minishell *shell, char **argv)
{
	LLINT num;

	ft_putendl_fd("exit", STDOUT_FILENO);
	if (count_argc(argv) == 1)
		return (SUCCESS);
	if (count_argc(argv) > 2)
	{
		shell->exit_status = 1;
		return (print_error_ft_exit(TOO_MANY_ARGUMENTS, NULL));
	}
	skip_spaces(&argv[1]);
	if (!is_arg_numeric(argv[1]))
	{
		shell->exit_status = 255;
		return (print_error_ft_exit(NUMERIC_ARGUMENT_REQUIRED, argv[1]));
	}
	num = ft_atoll(argv[1]);
	if (is_overflowing(num, argv[1]) == TRUE)
	{
		shell->exit_status = 255;
		return (print_error_ft_exit(ARG_OVERFLOWING, argv[1]));
	}
	store_exit_status(shell, num);
	return (SUCCESS);
}
