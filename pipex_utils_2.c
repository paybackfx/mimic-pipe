#include "pipex.h"

void cmd(char **str, char **paths, char **env, int *fd) {
  int i;
  char *tmp1;

  i = 0;
  dup2(fd[1], 1);
  close(fd[0]);
  close(fd[1]);
  if (!(str[0]))
    affi("command not found", 127);
  while (paths[i]) {
    tmp1 = ft_strjoin(paths[i], str[0]);
    if (str[0][0] == '/') {
      execve(str[0], str, env);
      affi("command not found", 127);
    }
    if (access(tmp1, X_OK) == 0)
      execve(tmp1, str, env);
    free(tmp1);
    i++;
  }
  affi("command not found", 127);
  return;
}

void open_split1(int x, char **env, char **argv, int *fd) {
  int i;
  char *line;
  char **paths;
  char *tmp;
  char **str;

  i = 0;
  line = check_path(env);
  paths = ft_split(line, ':');
  while (paths[i]) {
    tmp = ft_strjoin(paths[i], "/");
    free(paths[i]);
    paths[i] = tmp;
    i++;
  }
  str = ft_split(argv[x], ' ');
  cmd(str, paths, env, fd);
}

void children(char **argv, int i, char **env) {
  int fd[2];
  int id;

  if (pipe(fd) == -1)
    perror("error");
  id = fork();
  if (id == 0)
    open_split1(i, env, argv, fd);
  else {
    waitpid(id, 0, 0);
    close(fd[1]);
    dup2(fd[0], 0);
    close(fd[0]);
  }
}

void free_tab(char **tab) {
  int i;

  i = 0;
  if (!tab)
    return;
  while (tab[i]) {
    free(tab[i]);
    i++;
  }
  free(tab);
}
