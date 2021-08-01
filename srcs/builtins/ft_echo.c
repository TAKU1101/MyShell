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

static void		print_all_args(int i, int argc, char **argv)
{
	int last_args;

	last_args = argc - 1;
	while (i < argc)
	{
		ft_putstr_fd(argv[i], STDOUT_FILENO);
		if (i != last_args)
		{
			write(STDOUT_FILENO, " ", 1);
		}
		i++;
	}
}

static int		is_n_option_valid(char *option)
{
	int	i;

	if (ft_strncmp(option, "-n", 2))
	{
		return (FALSE);
	}
	i = 2;
	while (option[i])
	{
		if (option[i] != 'n')
		{
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

int				ft_echo(char **argv)
{
	int	i;
	int	argc;
	int	is_n_option_found;

	argc = count_argc(argv);
	is_n_option_found = FALSE;
	if (argc == 1)
	{
		write(STDOUT_FILENO, "\n", 1);
	}
	else
	{
		i = 1;
		while ((i < argc) && is_n_option_valid(argv[i]))
		{
			is_n_option_found = TRUE;
			i++;
		}
		print_all_args(i, argc, argv);
		if (!is_n_option_found)
		{
			write(STDOUT_FILENO, "\n", 1);
		}
	}
	return (SUCCESS);
}
