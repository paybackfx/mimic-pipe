#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char *ft_strnstr(const char *hay, const char *ne, size_t len) {
  size_t i;
  size_t j;
  if (*ne == '\0')
    return ((char *)hay);
  i = 0;
  j = 0;
  while (*(hay + i) && (i < len)) {
    while (*(hay + i + j) == *(ne + j) && i + j < len) {
      if (ne[j + 1] == '\0')
        return ((char *)(hay + i));
      j++;
    }
    i++;
    j = 0;
  }
  return (0);
}
