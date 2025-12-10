NAME        = pipex
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I includes -I libft -I gnl
RM          = rm -f

# Source Directories
SRCS_DIR    = srcs
LIBFT_DIR   = libft
GNL_DIR     = gnl

# Source Files
# Explicitly list source files to avoid picking up junk or deleted files if wildcard fails to update (unlikely but safe)
# Actually wildcard is fine, but I'll update dependencies.
SRCS        = srcs/pipex.c srcs/exec.c srcs/cleanup.c srcs/affi.c srcs/here_doc.c
LIBFT_SRCS  = $(wildcard $(LIBFT_DIR)/*.c)
GNL_SRCS    = $(wildcard $(GNL_DIR)/*.c)

# Object Files
OBJS        = $(SRCS:.c=.o)
LIBFT_OBJS  = $(LIBFT_SRCS:.c=.o)
GNL_OBJS    = $(GNL_SRCS:.c=.o)

# All Objects
ALL_OBJS    = $(OBJS) $(LIBFT_OBJS) $(GNL_OBJS)

# Rules
all: $(NAME)

$(NAME): $(ALL_OBJS)
	$(CC) $(CFLAGS) $(ALL_OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(ALL_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
