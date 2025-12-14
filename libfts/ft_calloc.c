#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*buff;

	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	buff = malloc(count * size);
	if (!buff)
		return (0);
	ft_bzero(buff, count * size);
	return (buff);
}
