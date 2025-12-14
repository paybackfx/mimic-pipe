#include "pipex.h"

char	*check_path(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strnstr(str[i], "PATH", ft_strlen(str[i])))
		{
			return (str[i] + 5);
		}
		i++;
	}
	return (NULL);
}

void	open_split0(t_data *data, char **env, char **argv, int argc)
{
	int	i;

	data->ac = argc;
	data->en = env;
	data->av = argv;
	i = 0;
	data->line = check_path(env);
	data->paths = ft_split(data->line, ':');
	while (data->paths[i])
	{
		data->tmp = ft_strjoin(data->paths[i], "/");
		free(data->paths[i]);
		data->paths[i] = data->tmp;
		i++;
	}
	data->str2 = ft_split(argv[argc - 2], ' ');
	data->str1 = ft_split(argv[2], ' ');
	if (ft_strcmp(argv[1], "here_doc"))
		data->fd1 = open(argv[1], O_RDONLY);
	data->fd2 = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (data->fd2 < 0 || data->fd1 < 0)
		affi("invalid fd", 1);
}

void	cmd1(t_data *data, char **env)
{
	int	i;

	i = 0;
	dup2(data->fd1, 0);
	dup2(data->fd[1], 1);
	close(data->fd[0]);
	if (!(data->str1[0]))
		affi("command not found", 127);
	while (data->paths[i])
	{
		data->tmp2 = ft_strjoin(data->paths[i], data->str1[0]);
		if (data->str1[0][0] == '/')
		{
			execve(data->str1[0], data->str1, env);
			affi("command not found", 127);
		}
		else if (access(data->tmp2, X_OK) == 0)
			execve(data->tmp2, data->str1, env);
		free(data->tmp2);
		i++;
	}
	affi("command not found", 127);
}

void	cmd2(t_data *data, char **env)
{
	int	i;

	i = 0;
	close(data->fd[0]);
	close(data->fd[1]);
	dup2(data->fd2, 1);
	close(data->fd2);
	if (!(data->str2[0]))
	{
		affi("command not found1", 127);
	}
	while (data->paths[i])
	{
		data->tmp1 = ft_strjoin(data->paths[i], data->str2[0]);
		if (data->str2[0][0] == '/')
		{
			execve(data->str2[0], data->str2, env);
			affi("command not found2", 127);
		}
		if (access(data->tmp1, X_OK) == 0)
			execve(data->tmp1, data->str2, env);
		free(data->tmp1);
		i++;
	}
	affi("command not found3", 127);
}
