#include "libft.h"

void	*ft_memset(void *p, int v, size_t c)
{
	size_t	i;

	i = 0;
	while (i < c)
	{
		*(unsigned char *)(p + i) = (unsigned char)v;
		i++;
	}
	return (p);
}
