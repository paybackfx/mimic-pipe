#include "get_next_line.h"

char	*check(char *stc, char *buffer, int fd)
{
	ssize_t	i;

	i = 1;
	while (i != 0 && ft_strchr1(stc) == 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			if (stc)
				free(stc);
			stc = 0;
			return (NULL);
		}
		buffer[i] = '\0';
		stc = ft_strjoin1(stc, buffer);
	}
	free(buffer);
	return (stc);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stc;
	char		*ll;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	stc = check(stc, buffer, fd);
	if (!stc)
		return (NULL);
	ll = ft_line(stc);
	stc = ft_reserve(stc);
	return (ll);
}
