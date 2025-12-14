#include "pipex.h"

void open_split(t_data *data, char **env, char **argv, int argc) {
  int i;

  data->ac = argc;
  data->en = env;
  data->av = argv;
  i = 0;
  data->line = check_path(env);
  data->paths = ft_split(data->line, ':');
  while (data->paths[i]) {
    data->tmp = ft_strjoin(data->paths[i], "/");
    free(data->paths[i]);
    data->paths[i] = data->tmp;
    i++;
  }
  data->str2 = ft_split(argv[argc - 2], ' ');
  data->str1 = ft_split(argv[3], ' ');
  data->fd2 = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
  data->lim = ft_strjoin(argv[2], "\n");
  if (data->fd2 < 0)
    affi("invalid fd", 1);
}

void cmd11(t_data *data, char **env) {
  int i;

  i = 0;
  dup2(data->fd1, 0);
  dup2(data->fd[1], 1);
  close(data->fd[0]);
  if (!(data->str1[0]))
    affi("command not found", 127);
  while (data->paths[i]) {
    data->tmp2 = ft_strjoin(data->paths[i], data->str1[0]);
    if (data->str1[0][0] == '/') {
      execve(data->str1[0], data->str1, env);
      affi("command not found", 127);
    } else if (access(data->tmp2, X_OK) == 0)
      execve(data->tmp2, data->str1, env);
    free(data->tmp2);
    i++;
  }
  affi("command not found", 127);
}

void cmd22(t_data *data, char **env) {
  int i;

  i = 0;
  dup2(data->fd2, 1);
  dup2(data->fd[0], 0);
  close(data->fd[1]);
  if (!(data->str2[0])) {
    affi("command not found", 127);
  }
  while (data->paths[i]) {
    data->tmp1 = ft_strjoin(data->paths[i], data->str2[0]);
    if (data->str2[0][0] == '/') {
      execve(data->str2[0], data->str2, env);
      affi("command not found", 127);
    }
    if (access(data->tmp1, X_OK) == 0)
      execve(data->tmp1, data->str2, env);
    free(data->tmp1);
    i++;
  }
  affi("command not found", 127);
}

void store(t_data *data, char **argv) {
  char *s;
  char *lim;

  lim = ft_strjoin(argv[2], "\n");
  close(data->fd[0]);
  s = get_next_line(0);
  while (s) {
    if (ft_strcmp(lim, s) == 0)
      break;
    write(data->fd[1], s, ft_strlen(s));
    s = get_next_line(0);
  }
  close(data->fd[1]);
}

int here_doc(t_data *data, char **argv) {
  store(data, argv);
  return (0);
}
