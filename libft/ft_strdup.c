#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*buff;
	int		i;

	buff = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	i = 0;
	if (!buff)
		return (NULL);
	while (*s1)
	{
		*(buff + i) = *s1++;
		i++;
	}
	*(buff + i) = '\0';
	return (buff);
}
