#ifndef LIBFT_H
#define LIBFT_H
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list {
  int content;
  int i;
  struct s_list *next;
} t_list;

void *ft_memset(void *p, int v, size_t c);
char *ft_strchr(const char *s, int c);
size_t ft_strlen(const char *str);
void ft_bzero(void *s, size_t n);
char *ft_strdup(const char *s1);
void *ft_calloc(size_t count, size_t size);
char *ft_substr(char const *s, unsigned int st, size_t l);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strdup(const char *s1);
char **ft_split(char const *s, char c);
int ft_atoi(const char *sr);
t_list *ft_lstnew(int content);
void ft_lstadd_front(t_list **lst, t_list *new);
int ft_lstsize(t_list *lst);
t_list *ft_lstlast(t_list *lst);
void ft_lstadd_back(t_list **lst, t_list *new);
char *ft_strnstr(const char *hay, const char *ne, size_t len);
int ft_strcmp(char *s1, char *s2);
int ft_strncmp(const char *s1, const char *s2, size_t n);
void ft_putstr_fd(char *s, int fd);
void ft_putendl_fd(char *s, int fd);
#endif
