#ifndef S21_CAT_H
#define S21_CAT_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>
#include <getopt.h>

typedef struct flags {
    bool n;
    bool b;
    bool e;
    bool s;
    bool v;
    bool t;
    int count;
} flags;



#endif  // S21_CAT_H
