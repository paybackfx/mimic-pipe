#include "get_next_line.h"

int ft_strlen1(char *str) {
  int i;

  i = 0;
  while (str[i]) {
    i++;
  }
  return (i);
}

char *ft_strjoin1(char *s1, char *s2) {
  char *al;
  size_t i;
  size_t j;

  i = -1;
  j = 0;
  if (s1 == NULL) {
    s1 = malloc(1);
    s1[0] = '\0';
  }
  if (s1 == 0 || s2 == 0)
    return (NULL);
  al = malloc(ft_strlen1(s1) + ft_strlen1(s2) + 1);
  if (!al)
    return (NULL);
  while (s1[++i]) {
    al[i] = s1[i];
  }
  while (s2[j])
    al[i++] = s2[j++];
  *(al + i) = '\0';
  free(s1);
  return (al);
}

int ft_strchr1(char *s) {
  int i;

  i = 0;
  if (s) {
    while (s[i]) {
      if (s[i] == '\n')
        return (1);
      i++;
    }
  }
  return (0);
}

char *ft_line(char *stc) {
  char *ll;
  int i;

  i = 0;
  if (*stc == '\0')
    return (NULL);
  while (stc[i] != '\n' && stc[i])
    i++;
  if (stc[i] == '\n')
    i++;
  ll = malloc(sizeof(char) * i + 1);
  i = 0;
  while (stc[i] != '\n' && stc[i]) {
    ll[i] = stc[i];
    i++;
  }
  if (stc[i] == '\n')
    ll[i++] = '\n';
  ll[i] = '\0';
  return (ll);
}

char *ft_reserve(char *stc) {
  int i;
  int j;
  char *rev;

  i = 0;
  j = 0;
  while (stc[i] != '\n' && stc[i])
    i++;
  if (stc[i] == '\0') {
    free(stc);
    return (NULL);
  }
  rev = malloc(sizeof(char) * ft_strlen1(stc) - i + 1);
  if (!rev)
    return (NULL);
  while (stc[i]) {
    i++;
    rev[j] = stc[i];
    j++;
  }
  rev[j] = '\0';
  free(stc);
  return (rev);
}
