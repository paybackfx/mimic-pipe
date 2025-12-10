#include "pipex.h"

static char *find_path_in_env(char **env) {
  int i;

  i = 0;
  while (env && env[i]) {
    if (ft_strncmp(env[i], "PATH=", 5) == 0)
      return (env[i] + 5);
    i++;
  }
  return (NULL);
}

static char *get_cmd_path(char *cmd, char **env) {
  char **paths;
  char *path_env;
  char *part_path;
  char *full_path;
  int i;

  if (ft_strchr(cmd, '/')) {
    if (access(cmd, X_OK) == 0)
      return (ft_strdup(cmd));
    return (NULL);
  }
  path_env = find_path_in_env(env);
  if (!path_env)
    return (NULL);
  paths = ft_split(path_env, ':');
  if (!paths)
    return (NULL);
  i = -1;
  while (paths[++i]) {
    part_path = ft_strjoin(paths[i], "/");
    full_path = ft_strjoin(part_path, cmd);
    free(part_path);
    if (access(full_path, X_OK) == 0) {
      free_str_array(paths);
      return (full_path);
    }
    free(full_path);
  }
  free_str_array(paths);
  return (NULL);
}

void exec_cmd(char *cmd_str, char **env) {
  char **cmd_args;
  char *cmd_path;

  if (!cmd_str || !*cmd_str)
    return;
  cmd_args = ft_split(cmd_str, ' ');
  if (!cmd_args)
    exit(1);
  if (!cmd_args[0]) {
    free_str_array(cmd_args);
    ft_putstr_fd("pipex: command not found: \n", 2);
    exit(127);
  }
  cmd_path = get_cmd_path(cmd_args[0], env);
  if (!cmd_path) {
    ft_putstr_fd("pipex: command not found: ", 2);
    ft_putendl_fd(cmd_args[0], 2);
    free_str_array(cmd_args);
    exit(127);
  }
  if (execve(cmd_path, cmd_args, env) == -1) {
    perror(cmd_args[0]);
    free(cmd_path);
    free_str_array(cmd_args);
    exit(127);
  }
}
