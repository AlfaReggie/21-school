#include "s21_grep.h"


void* safety_malloc(size_t size)
{
  void* pointer = malloc(size);
  if (!pointer)
    exit(1);
  return pointer;
}

void* safety_realloc(void* ptr, size_t newsize)
{
  ptr = realloc(ptr, newsize);
  if (!ptr)
    exit(1);
  return ptr;
}


void execute(int argc, char **argv)
{
    int opt = 0;
    int num_flags = 0;
    t_flag* flags = NULL;

    while ((opt = getopt(argc, argv, "e:ivclnhsf:o")) != EOF)
    {
        if (opt == '?')
          exit(2);
        if (!flags)
          flags = (t_flag*)safety_malloc(sizeof(t_flag));
        else
          flags = (t_flag*)safety_realloc(flags, sizeof(t_flag)*(num_flags+1));
        printf("Start\n");
        printf("opt: %c\n", (char)opt);
        printf("optarg: %s\n", optarg);
        flags[num_flags].flag = opt;
        flags[num_flags].template = optarg ? strdup(optarg) : optarg;
        printf("flag[%d].flag: %c\n", num_flags, flags[num_flags].flag);
        printf("flag[%d].template: %s\n", num_flags, flags[num_flags].template);
        printf("num_flags: %d\n\n", num_flags);
        num_flags++;
    }
}


int main(int argc, char** argv)
{
    execute(argc, argv);
    return 0;
}
