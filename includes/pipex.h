#ifndef PIPEX_H
#define PIPEX_H
#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

typedef struct s_data {
  int fd[2];
  int pid1;
  int pid2;
  int infile;
  int outfile;
  int status;
} t_data;

/* exec.c */
void exec_cmd(char *cmd_str, char **env);

/* cleanup.c */
void free_str_array(char **arr);

/* affi.c */
void affi(const char *c, int n);
void affi2(const char *c);

/* here_doc.c */
int here_doc(t_data *data, char **argv);

#endif