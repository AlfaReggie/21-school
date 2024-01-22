#include "s21_cat.h"
#include "func.h"



int main(int argc, char **argv) {
    flags flag = {0};
    if (argc == 1) {
        cat_print(stdin, &flag);
    } else {
        if (argv[1][0] == '-') {
            char errFlag = parse_flags(argc, argv, &flag);
            if (!flag.count && optind) {
                printf("cat: illegal option -- %c", errFlag);
            } else {
                cat_file(argc, argv, &flag);
            }
        } else {
            cat_file(argc, argv, &flag);
        }
    }
    return 0;
}
