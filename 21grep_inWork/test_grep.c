#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>

#define SIZE 4096

typedef struct s_flags
{
    
    char flag;
    char template[SIZE];

} t_flags;

// void* safety_malloc(size_t size) {
//     void* pointer = malloc(size);
//     if (!pointer)
//         exit(1);
//     return pointer;
// }

// void* safety_realloc(void* ptr, size_t newsize) {
//     ptr = realloc(ptr, newsize);
//         if (!ptr)
//             exit(1);
//     return ptr;
// }

// void error(char *mesg, int errnum)
// {
//   if (errnum)
//     fprintf(stderr, "s21_grep: %s: %s\n", mesg, strerror(errnum));
//   else
//     fprintf(stderr, "s21_grep: %s\n", mesg);
// }

// void fatal(char *mesg, int errnum)
// {
//   error(mesg, errnum);
//   exit(2);
// }

// void *extended_realloc(void *ptr, size_t size)
// {
//   void *result;
//   if (ptr)
//     result = realloc(ptr, size);
//   else
//     result = malloc(size);
//   if (size && !result)
//     fatal("memory exhausted", 0);
//   return result;
// }

// void* safety_malloc(size_t size)
// {
//   void* pointer = malloc(size);
//   if (!pointer)
//     exit(1);
//   return pointer;
// }

// void* safety_realloc(void* ptr, size_t newsize)
// {
//   ptr = realloc(ptr, newsize);
//   if (!ptr)
//     exit(1);
//   return ptr;
// }


void execute(int argc, char **argv)
{
    int opt = 0;
    int num_flags = 0;
    t_flags* flags = NULL;

    while ((opt = getopt(argc, argv, "e:ivclnhsf:o")) != EOF)
    {
        if (opt == '?')
            exit(2);
        printf("Start\n");
        printf("opt: %c\n", (char)opt);
        printf("optarg: %s\n", optarg);
        flags[num_flags].flag = opt;
        flags->template[num_flags] = optarg;
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
