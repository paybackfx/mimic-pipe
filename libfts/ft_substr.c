#include "libft.h"

char	*ft_substr(char const *s, unsigned int st, size_t l)
{
	char	*buff;
	size_t	i;
	size_t	d;

	i = 0;
	d = 0;
	if (!s)
		return (NULL);
	if (st >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - st < l)
		d = ft_strlen(s) - st;
	else
		d = (l);
	buff = (char *)malloc(d + 1);
	if (!buff)
		return (NULL);
	while (s[st] && i < l)
	{
		*(buff + i) = *(s + st);
		i++;
		st++;
	}
	*(buff + i) = '\0';
	return (buff);
}
