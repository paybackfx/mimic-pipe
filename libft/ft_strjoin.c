#include "libft.h"

static char	*fill(char const *s1, char const *s2)
{
	size_t	s;
	char	*al;
	size_t	i;

	i = 0;
	s = ft_strlen(s1) + ft_strlen(s2);
	al = malloc(s + 1);
	if (!al)
		return (NULL);
	while (*s1)
	{
		*(al + i) = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		*(al + i) = *s2;
		i++;
		s2++;
	}
	*(al + i) = '\0';
	return (al);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	if (s1 == 0 && s2 == 0)
		return (NULL);
	if (s1 == NULL)
		ft_strdup(s2);
	if (s2 == NULL)
		ft_strdup(s1);
	return (fill(s1, s2));
}
