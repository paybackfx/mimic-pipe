#include "pipex.h"

int	safe_exit1(t_data *data, char **env, int *status)
{
	data->pid1 = fork();
	if (data->pid1 == -1)
		affi("fork", 1);
	if (data->pid1 == 0)
		cmd22(data, env);
	else
	{
		close(data->fd[0]);
		close(data->fd[1]);
		waitpid(-1, 0, 0);
		waitpid(data->pid1, status, 0);
		free(data);
	}
	if (WIFEXITED(*status))
		return (WEXITSTATUS(*status));
	return (0);
}

char	*check_path1(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strnstr(str[i], "PATH", ft_strlen(str[i])))
			return (str[i] + 5);
		i++;
	}
	return (NULL);
}
