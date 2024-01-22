//#include <stdio.h>
//#include <stdint.h>
//#include <stdlib.h>
//#include <errno.h>
//#include <getopt.h>     //  Библиотека для применения функции getopt
//#include <stdbool.h>    //  Библиотека которая содержит булевые значения True and False
#include "CatAscii.h"
#include "s21_cat.h"


typedef struct {        //  структура флагов которые у нас есть    
    bool number_b;
    bool number_e;
    bool number_n;
    bool number_s;
    bool number_t;
    bool number_v;
} Flags;

Flags ReadFlags(int argc, char *argv[]) {       //  Функция для чтения флагов   
   struct option long_opt[] = {                 // Структура длинных опций    
        {"number-nonblank", no_argument, NULL, 'b'},
        {"number", no_argument, NULL, 'n'},
        {"squeeze-blank", no_argument, NULL, 's'},
        {NULL, 0, NULL, 0}
    };

    int valid_flag;     // Переменная, которая хранит в себе действующие, действительные флаги, передаваемые функцией #getopt_long
    Flags value = {0};
    while ((valid_flag = getopt_long(argc, argv, "benstvET", long_opt, NULL)) != -1) {      // Пока функция getopt_long != -1, есть в примере manual
        switch (valid_flag) {
        case 'b':
            value.number_b = true;
            break;
        case 'v':
            value.number_v = true;
            break;
        case 'e':
            value.number_e = true;
            value.number_v = true;
            break;
        case 'n':
            value.number_n = true;
            break;
        case 's':
            value.number_s = true;
            break;
        case 't':
            value.number_t = true;
            value.number_v = true;
            break;
        case 'E':
            value.number_e = true;
            break;
        case 'T':
            value.number_t = true;
            break;  
        default:
            break;
        }
    }
    return value;
}


void CatF(FILE *file, Flags value, const char *table[]) {
    int c = 0;
    int e_ol = '\n';        // end of line
    bool cond = false;      // условие флаг s
    int line = 0;           // счётчик строк
    while ((fread(&c, 1, 1, file)) > 0) {
        if (e_ol == '\n'){
            if(value.number_s && c == '\n') {   // флаг s
                if(cond)
                    continue;
                cond = true;
            }
            else
                cond = false;
            if(value.number_b) {   
                if (c != '\n')                  // флаг b
                printf("%6d\t", ++line);
            }
            else if (value.number_n)            // флаг n
            {
                printf("%6d\t", ++line);
            }
            
        }
        if(!*table[c])
            printf("%c", '\0');
        else
            printf("%s", table[c]);
        e_ol = c;
    }
}

void Cat(int argc, char *argv[], Flags value, const char *table[]) {
    for (char **fname = &argv[1], **end = &argv[argc]; fname != end; ++fname) {
        if (**fname == '-')
            continue;
        FILE *file = fopen(*fname, "rb");
        if(errno) {
            fprintf(stderr, "%s", argv[0]);
            perror(*fname);
            continue;

        }
        CatF(file, value, table);
        fclose(file);

    }
}

int main(int argc, char *argv[]) {      // Временно для проверки работы функции чтения, запускаем make, затем ./s21_cat -(любой флаг), должны увидеть номер флага или номера 
    Flags value = ReadFlags(argc, argv);
    const char *table[256];
    CatAsciiTable(table);
    if (value.number_e)
        CatNumber_e(table);
    if (value.number_t)
        CatNumber_t(table);
    if (value.number_v)
        CatNumber_v(table);

    Cat(argc, argv, value, table);

    return 0;   
}


