#include "libft.h"

static int	word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (*(s + i))
	{
		if (*(s + i) != c && i > 0 && (*(s + i + 1) == c || *(s + i
					+ 1) == '\0'))
			count++;
		i++;
	}
	return (count + 1);
}

static void	*freealloc(char **splited, int j)
{
	int	i;

	i = 0;
	while (i < j)
		free(splited[i++]);
	free(splited);
	return (NULL);
}

static int	skipc(const char *s, char c)
{
	int	i;

	i = 0;
	while (*(s + i) != c && *(s + i))
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**ss;
	int		i;
	int		j;
	int		k;

	ss = ft_calloc(word(s, c) + 1, sizeof(char *));
	if (!s || !ss)
		return (NULL);
	i = 0;
	j = 0;
	while (*(s + i))
	{
		if (*(s + i) != c)
		{
			k = skipc(s + i, c);
			*(ss + j) = ft_substr(s, i, k);
			if (*(ss + j) == NULL)
				return (freealloc(ss, j));
			j++;
			i += k;
		}
		else
			i++;
	}
	return (ss);
}
