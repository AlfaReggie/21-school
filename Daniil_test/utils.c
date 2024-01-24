#include "s21_grep.h"

void error(char *mesg, int errnum)
{
  if (errnum)
    fprintf(stderr, "s21_grep: %s: %s\n", mesg, strerror(errnum));
  else
    fprintf(stderr, "s21_grep: %s\n", mesg);
}

void fatal(char *mesg, int errnum)
{
  error(mesg, errnum);
  exit(2);
}

void *extended_realloc(void *ptr, size_t size)
{
  void *result;
  if (ptr)
    result = realloc(ptr, size);
  else
    result = malloc(size);
  if (size && !result)
    fatal("memory exhausted", 0);
  return result;
}
