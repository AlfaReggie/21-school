#ifndef S21_GREP
# define S21_GREP

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <getopt.h>



typedef struct s_flag
{
    char flag;
    char* template;
} t_flag;


void *extended_realloc(void *ptr, size_t size);
void fatal(char *mesg, int errnum);


#endif
