#include "pipex.h"

int safe_exit(t_data *data, char **env) {
  int status;

  data->pid1 = fork();
  if (data->pid == -1)
    affi("fork", 1);
  if (data->pid1 == 0)
    cmd2(data, env);
  else {
    close(data->fd[0]);
    close(data->fd[1]);
    waitpid(-1, NULL, 0);
    waitpid(data->pid1, &status, 0);
    free_tab(data->paths);
    free_tab(data->str1);
    free_tab(data->str2);
    free(data);
  }
  if (WIFEXITED(status))
    return (WEXITSTATUS(status));
  return (0);
}

int loopx(t_data *data) {
  data->in = 3;
  while (data->in < data->ac - 2) {
    children(data->av, data->in, data->en);
    data->in++;
  }
  return (safe_exit(data, data->en));
}

int closeparent(t_data *data) {
  close(data->fd[1]);
  dup2(data->fd[0], 0);
  close(data->fd[0]);
  return (loopx(data));
}

int main(int argc, char **argv, char **env) {
  t_data *data;

  data = malloc(sizeof(t_data));
  if (argc >= 5) {
    open_split0(data, env, argv, argc);
    if (pipe(data->fd) == -1)
      affi("pipe", 1);
    data->pid = fork();
    if (data->pid == -1)
      affi("fork", 1);
    if (data->pid == 0) {
      if (ft_strcmp(argv[1], "here_doc") == 0)
        here_doc(data, argv);
      else
        cmd1(data, env);
      exit(1);
    } else
      return (closeparent(data));
  } else
    affi("no valid argument ", 1);
  return (0);
}
