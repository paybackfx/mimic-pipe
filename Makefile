SRCS            =   libfts/ft_bzero.c libfts/ft_calloc.c libfts/ft_memset.c\
                    libfts/ft_split.c libfts/ft_strchr.c libfts/ft_strdup.c\
                    libfts/ft_strjoin.c libfts/ft_strlen.c libfts/ft_strnstr.c\
                    libfts/ft_substr.c pipex_utils.c pipex.c affi.c\
                    pipex_utils_2.c libfts/ft_strcmp.c here_doc.c \
                    ./get_next_line_s/get_next_line.c  ./get_next_line_s/get_next_line_utils.c \
                    here_doc_2.c

OBJS            = $(SRCS:.c=.o)

CC              = cc
RM              = rm -f
CFLAGS          = -Wall -Wextra -Werror

NAME            = pipex.a

# Final executable name
PROG            = pipex

all:            $(PROG)

$(NAME):        $(OBJS)
				ar rc $(NAME) $(OBJS)

$(PROG):        $(NAME)
				$(CC) pipex.c $(NAME) -o $(PROG)

clean:
				$(RM) $(OBJS)

fclean:         clean
				$(RM) $(NAME) $(PROG)

re:             fclean all

.PHONY:         all clean fclean re
