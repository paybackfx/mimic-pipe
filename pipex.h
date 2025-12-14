#ifndef PIPEX_H
#define PIPEX_H
#include "./get_next_line_s/get_next_line.h"
#include "./libfts/libft.h"
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

typedef struct s_data {
  char *line;
  char **paths;
  char **cmd;
  int fd1;
  int fd2;
  int fd[2];
  pid_t pid;
  char **str1;
  char **str2;
  int i;
  int x;
  int pid1;
  char *tmp;
  char *tmp1;
  char *tmp2;
  int in;
  int ac;
  char **av;
  char **en;
  char *lim;
} t_data;

char *check_path(char **str);
char *check_path1(char **str);
void open_splitx(t_data *data, char **env, char **argv);
void open_split(t_data *data, char **env, char **argv, int argc);
void open_split0(t_data *data, char **env, char **argv, int argc);
void open_split1(int x, char **env, char **argv, int *fd);
void children(char **argv, int i, char **env);
void cmd(char **str, char **paths, char **env, int *fd);
void cmd1(t_data *data, char **env);
void cmd11(t_data *data, char **env);
void cmd2(t_data *data, char **env);
void cmd22(t_data *data, char **env);
void affi(const char *c, int n);
void affi2(const char *c);
int here_doc(t_data *data, char **argv);
void free_tab(char **tab);
int safe_exit1(t_data *data, char **env, int *status);

#endif