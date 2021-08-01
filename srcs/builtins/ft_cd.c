#include "builtins.h"

static int		does_directory_exist(char *dirname)
{
	DIR		*dir;

	if ((dir = opendir(dirname)) == NULL)
	{
		return (FALSE);
	}
	closedir(dir);
	return (TRUE);
}

static int		go_to_home_directory(t_minishell *shell)
{
	char	*home_dir_path;
	int		result;

	home_dir_path = get_env_value(shell, "HOME");
	if (!home_dir_path)
	{
		ft_putendl_fd("cd: HOME not set", STDOUT_FILENO);
		return (ENV_NOT_SET);
	}
	if (!does_directory_exist(home_dir_path))
	{
		print_error_ft_cd(home_dir_path);
		return (DIR_NOT_FOUND);
	}
	update_oldpwd(shell);
	result = chdir(home_dir_path);
	free_add_null_pointer(home_dir_path);
	update_pwd(shell);
	return (result);
}

static int		go_to_oldpwd(t_minishell *shell)
{
	int		result;
	char	*oldpwd_path;

	oldpwd_path = get_env_value(shell, "OLDPWD");
	if (!oldpwd_path)
	{
		ft_putendl_fd("cd: OLDPWD not set", STDOUT_FILENO);
		return (ENV_NOT_SET);
	}
	if (!does_directory_exist(oldpwd_path))
	{
		print_error_ft_cd(oldpwd_path);
		return (DIR_NOT_FOUND);
	}
	ft_putendl_fd(oldpwd_path, STDOUT_FILENO);
	update_oldpwd(shell);
	result = chdir(oldpwd_path);
	free_add_null_pointer(oldpwd_path);
	update_pwd(shell);
	return (result);
}

static int		change_directory_with_path(t_minishell *shell, char *path)
{
	int result;

	if (!(does_directory_exist(path)))
	{
		return (CHDIR_ERROR);
	}
	update_oldpwd(shell);
	result = chdir(path);
	update_pwd(shell);
	return (result);
}

int				ft_cd(char **argv, t_minishell *shell)
{
	int		result;

	if (!argv[1])
	{
		result = go_to_home_directory(shell);
		return (result);
	}
	if (argv[1][0] == '\0')
	{
		update_oldpwd(shell);
		return (SUCCESS);
	}
	if (!ft_strcmp(argv[1], "-"))
		result = go_to_oldpwd(shell);
	else
		result = change_directory_with_path(shell, argv[1]);
	if (result == CHDIR_ERROR)
	{
		print_error_ft_cd(argv[1]);
		result = ERROR;
	}
	return (result);
}
