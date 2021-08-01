#include "bin_list_units.h"

char	*join_path(char *dir_path, char *file_name)
{
	char	*tmp;
	char	*file_path;
	int		dir_path_len;

	dir_path_len = ft_strlen(dir_path);
	if (dir_path[dir_path_len - 1] == '/')
	{
		if (!(tmp = ft_strjoin(dir_path, file_name)))
			return (NULL);
		return (tmp);
	}
	else
	{
		if (!(tmp = ft_strjoin(dir_path, "/")))
			return (NULL);
		if (!(file_path = ft_strjoin(tmp, file_name)))
			return (NULL);
		free_add_null_pointer(tmp);
		return (file_path);
	}
	return (NULL);
}

int		set_path_file(char *dir_path, t_bins **bins)
{
	DIR				*dir;
	struct dirent	*dent;
	t_bins			*new;
	char			*file_path;

	if ((dir = opendir(dir_path)) == NULL)
		return (EXIT_FAILURE);
	while ((dent = readdir(dir)) != NULL)
	{
		if (ft_strcmp(dent->d_name, "..") && ft_strcmp(dent->d_name, ".") &&
				(dent->d_type == DT_REG || dent->d_type == DT_LNK))
		{
			if (!(file_path = join_path(dir_path, dent->d_name)))
				return (EXIT_FAILURE);
			if (!(new = bin_lstnew(file_path, ft_strdup(dent->d_name))))
				return (EXIT_FAILURE);
			bin_lstadd_back(bins, new);
		}
	}
	closedir(dir);
	return (EXIT_SUCCESS);
}

int		initialize_bins(t_minishell *shell)
{
	char	*path_line;
	char	**paths;
	t_bins	*bins;
	int		i;

	if ((path_line = get_env_value(shell, "PATH")) == NULL)
		if (!(path_line = ft_strdup("")))
			return (EXIT_FAILURE);
	paths = ft_split(path_line, ':');
	free_add_null_pointer(path_line);
	i = 0;
	bins = NULL;
	while (paths[i])
	{
		set_path_file(paths[i], &bins);
		free_add_null_pointer(paths[i]);
		i++;
	}
	free(paths);
	paths = NULL;
	shell->bins = bins;
	return (EXIT_SUCCESS);
}
