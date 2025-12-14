#include "pipex.h"

void	affi(const char *c, int n)
{
	perror(c);
	exit(n);
}

void	affi2(const char *c)
{
	write(2, &c, ft_strlen(c));
	return ;
}
