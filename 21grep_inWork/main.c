#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <getopt.h>


#define FLAGS_COUNT 10
#define SIZE 32
#define BUF_SIZE 4096


struct s_map_flag;


typedef struct s_map_flag {
    char key;
    bool val;
} t_map_flag;


typedef struct s_flags {
    char *patterns[SIZE];
    char *patterns_files[SIZE];
    char *files[SIZE];
    char pattern[BUF_SIZE];
    
    // struct s_dick_flag dicks[10] = {
    //     {'e', false}, {'f', false},
    //     {'i', false}, {'v', false},
    //     {'c', false}, {'l', false},
    //     {'n', false}, {'h', false}, 
    //     {'s', false}, {'o', false}
    // };
    struct s_map_flag dicks;

    int filesCount;
    int matchesCount;
} t_flags;


int main() {
    t_flags f = {0};
    f.dicks.key = 'e';
    f.dicks.val = false;
    // t_map_flag a[2] = {{'e', true}, {'s', false}};
    printf("%d", (int)(f.dicks.key));
    return 0;
}