#include "pipex.h"

static void read_until_limiter(int fd_write, char *limiter) {
  char *line;
  int len;

  len = ft_strlen(limiter);
  while (1) {
    write(1, "heredoc> ", 9);
    line = get_next_line(0);
    if (!line)
      break;
    if (ft_strncmp(line, limiter, len) == 0 && line[len] == '\n') {
      free(line);
      break;
    }
    write(fd_write, line, ft_strlen(line));
    free(line);
  }
}

int here_doc(t_data *data, char **argv) {
  int fd[2];
  pid_t pid;

  (void)data;
  if (pipe(fd) == -1)
    affi("pipe", 1);
  pid = fork();
  if (pid == -1)
    affi("fork", 1);
  if (pid == 0) {
    close(fd[0]);
    read_until_limiter(fd[1], argv[2]);
    close(fd[1]);
    exit(0);
  } else {
    close(fd[1]);
    waitpid(pid, NULL, 0);
    return (fd[0]);
  }
}
