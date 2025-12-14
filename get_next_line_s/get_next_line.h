#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strchr1(char *s);
char	*ft_strjoin1(char *s1, char *s2);
int		ft_strlen1(char *str);
char	*ft_line(char *stc);
char	*ft_reserve(char *stc);
char	*get_next_line(int fd);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif
#endif
