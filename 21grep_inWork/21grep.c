#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <getopt.h>
#include <regex.h>

#define FLAGS_COUNT 10
#define SIZE 4096
#define BUF_SIZE 4096

typedef struct s_dict_flag {
    char key;
    bool val;
    char** templates;
} t_dict_flag;

typedef struct s_flags {
    char *patterns[SIZE];
    char *patterns_files[SIZE];
    char *files[SIZE];
    char pattern[BUF_SIZE];
    
    struct s_dict_flag dict[FLAGS_COUNT];

    int filesCount;
    int matchesCount;
    int lenPattern;
} t_flags;

//void execute(int argc, char **argv)
//{
//    int opt = 0;
//    int num_flags = 0;
//    t_flags* flags = NULL;
//    char template[BUFFER];
//    char flag[BUFFER];
//
//    while ((opt = getopt(argc, argv, "e:ivclnhsf:o")) != -1)
//    {
//        if (opt == '?')
//          exit(2);
//
//        printf("Start\n");
//        printf("opt: %c\n", (char)opt);
//        printf("optarg: %s\n", optarg);
//    }
//}

{
    int opt = 0;
    int num_flags = 0;
    t_flags* flags = NULL;
    char template[BUFFER];
    char flag[BUFFER];

    while ((opt = getopt(argc, argv, "e:ivclnhsf:o")) != -1)
    {
        if (opt == '?')
          exit(2);

        printf("Start\n");
        printf("opt: %c\n", (char)opt);
        printf("optarg: %s\n", optarg);
    }
}

void flagParser(char args, t_flags* flag) {
    int opt = 0;
    char flagList[FLAGS_COUNT] = "efivclnhso";
    for (int i = 0; i < FLAGS_COUNT; i++) {   
        if (args == (int)(flag->dict[i].key)) {
            flag->dict[i].val = true;
            break;
        } else {
            printf("s21_grep: invalid option -- %c", args);
        }
    }
}

void initFlags(t_flags* flag) {
    char flagList[FLAGS_COUNT] = "efivclnhso";
    for (int i = 0; i < FLAGS_COUNT; i++) 
    {
        flag->dict[i].key = flagList[i];
        flag->dict[i].val = false;
    }
}

bool getFlagVal(t_flags flag, char key) {
    for (int i = 0; i < FLAGS_COUNT; i++) {
        if (flag.dict[i].key == key) {
            return flag.dict[i].val;
        }
    }
    return false;
}

void setFlagVal(t_flags* flag, char key, bool change) {
    for (int i = 0; i < FLAGS_COUNT; i++) {
        if (flag->dict[i].key == key) {
            flag->dict[i].val = change;
        }
    }
}

// void parse_e_flag(t_flags *flag, char *argv[], int *i, int j,
//                   int *patterns_count) {
//   setFlagVal(flag, 'e', true);
//   if (argv[*i][j] != '\0') {
//     char buf[BUF_SIZE] = "";
//     strcat(buf, argv[*i] + j);
//     flag->patterns[(*patterns_count)++] = buf;
//   } else {
//     flag->patterns[(*patterns_count)++] = argv[++(*i)];
//   }
// }


// void parse_f_flag(t_flags *flag, char *argv[], int *i, int j,
//                   int *pattern_files_count) {
//   setFlagVal(flag, 'f', true);
//   if (argv[*i][j] != '\0') {
//     char buf[BUF_SIZE] = "";
//     strcat(buf, argv[*i] + j);
//     flag->patterns_files[(*pattern_files_count)++] = buf;
//   } else {
//     flag->patterns_files[(*pattern_files_count)++] = argv[++(*i)];
//   }
// }

// void optionScan(int argc, char** argv, t_flags* flag) {
//     int patternCount = 0;
//     int pattern_files_count = 0;
//     for (int i = 1; i < argc; i++) {
//         if (argv[i][0] == '-') {
//             if (argv[i][1] == 'e') {
//                 parse_e_flag(flag, argv, &i, 2, &patternCount);
//             } else if (argv[i][1] == 'f') {
//                 parse_f_flag(flag, argv, &i, 2, &pattern_files_count);
//             } else {
//                 flagParser(argc, argv, flag);
//             }
//         } else if (!(getFlagVal(*flag, 'e')) && !(getFlagVal(*flag, 'f'))) {
//             setFlagVal(flag, 'e', true);
//             flag->patterns[patternCount++] = argv[i];
//         } else {
//             flag->files[flag->filesCount++] = argv[i];
//         }
//     }
//     setFlagVal(flag, 'o', !(getFlagVal(*flag, 'l') || getFlagVal(*flag, 'v') || getFlagVal(*flag, 'c')));
// }


void optionScan(int argc, char** argv, t_flags* flag) {
    char flagList[FLAGS_COUNT] = "efivclnhso";
        // char flag = flagList[i];
        int j = 1;
        while (argc > j++) /* начинаем парсинг */
        {
            char* arg = argv[j];
            if (arg[0] == '-')
            { /* работаем с флагами */
                    int i = 1;
                    while (isFlag(arg[i])) {
                        /* находим соответсвующий флаг в flag и ставим true */
                        if (arg[i] == '-' || arg[i] == ' ') {
                            continue;
                        } else {
                            flagParser(arg[i], flag);
                        }
                        ++i;
                    }
                    {
                        /* флаги закончились, начинаем работать template */
                        
                    }
            }
            else { /* работаем с template */

            }
        } /* парсинг закончился */

        execute();
}

bool isFlag(char sign) {
    char flagList[FLAGS_COUNT] = "efivclnhso";
    for (int i = 0; i < FLAGS_COUNT; i++) {
        if (sign == flagList[i]) {
            return true;
        }
    }
    return false;
}

// void cook_pattern_files(t_flags* flag, int num) {
//   char buf[BUF_SIZE];
//   FILE *fp = fopen(flag->patterns_files[num], "r");
//   if (fp) {
//     while (fgets(buf, BUF_SIZE, fp)) {
//       char *c = buf + strlen(buf) - 1;
//       if (*c == '\n') *c = '\0';
//       strcat(strcat(flag->pattern, !strlen(flag->pattern) ? "" : "|"),
//              !strlen(buf) ? "." : buf);
//     }
//   } else
//     fprintf(stderr, "s21_grep: %s: No such file or directory\n",
//             flag->patterns_files[num]);
// }

// void cook_pattern(t_flags* flag) {
//   for (int i = 0; flag->patterns[i]; i++)
//     strcat(strcat(flag->pattern, !strlen(flag->pattern) ? "" : "|"),
//            !strlen(flag->patterns[i]) ? "." : flag->patterns[i]);
//   for (int i = 0; flag->patterns_files[i]; i++) cook_pattern_files(flag, i);
// }

// void cook_with_o(regex_t regex, char *line, t_flags* flag) {
//   while (!regexec(&regex, line, 0, NULL, 0)) { //Пока есть совпадения в строке
//     char buf[BUF_SIZE] = "";
//     strcpy(buf, line);
//     int left = 0; //индекс крайнего левого символа в совпадающем участке
//     int right = strlen(buf); //индекс крайнего правого символа в совпадающем участке
//     while (!regexec(&regex, buf + left, 0, NULL, 0)) left++; //пока есть совпадение смещаем левый индекс
//     left--; //перескочив, важно вернутся
//     while (!regexec(&regex, buf + left, 0, NULL, 0)) { //затем правый, попутно обнуляя неподходящие символы
//       right--;
//       buf[right] = 0;
//     }
//     buf[right] = line[right];
//     right++; //тот же принцип что и с левым
//     if (!(getFlagVal(*flag, 'v'))) printf("%s\n", buf + left); //выводим найденное совпадение
//     int len = right - left + 1;
//     for (int i = 0; i < len; i++) { //удаляем из строки найденное совпадение
//       line[left++] = line[right++];
//     }
//   }
//   if (getFlagVal(*flag, 'v')) printf("%s", line); //если была опцияя с инвертацие выводим оставшуюся без совпадений строку
// }

// void cook_main_data(t_flags* flag, char *line, char *file_name, int num) {
//   regex_t regex;
//   if (!regcomp(&regex, flag->pattern,
//                getFlagVal(*flag, 'i') ? REG_ICASE : REG_EXTENDED)) {
//     if (regexec(&regex, line, 0, NULL, 0) == getFlagVal(*flag, 'v')) {
//       flag->matchesCount++;
//       if ((getFlagVal(*flag, 'c') || getFlagVal(*flag, 'l')) == 0) {
//         if (flag->filesCount > 1 && !(getFlagVal(*flag, 'h'))) printf("%s:", file_name);
//         if (getFlagVal(*flag, 'n')) printf("%d:", num);
//         if (!(getFlagVal(*flag, 'o')))
//           fputs(line, stdout);
//         else
//           cook_with_o(regex, line, flag);
//       }
//     }
//     regfree(&regex);
//   }
// }

// void cook_aux_data(t_flags* flag, char *file_name) {
//   if (getFlagVal(*flag, 'c')) {
//     if (getFlagVal(*flag, 'l')) {
//       flag->filesCount > 1 ? printf("%s:1\n", file_name) : printf("1\n");
//     } else {
//       if (flag->filesCount > 1) printf("%s:", file_name);
//       printf("%d\n", flag->matchesCount);
//     }
//   }
//   if (getFlagVal(*flag, 'l') && flag->matchesCount) printf("%s\n", file_name);
// }

// void grep_it(t_flags* flag) {
//   cook_pattern(flag);
//   for (int i = 0; i < flag->filesCount; i++) {
//     FILE *fp = fopen(flag->files[i], "r");
//     if (fp) {
//       char buf[BUF_SIZE];
//       int num = 1;
//       while (fgets(buf, BUF_SIZE, fp)) {
//         int len = strlen(buf); //обрабатываем последнюю строку
//         if (buf[len - 1] != '\n') {
//           buf[len + 1] = 0;
//           buf[len] = '\n';
//         }
//         cook_main_data(flag, buf, flag->files[i], num);
//         num++;
//       }
//       cook_aux_data(flag, flag->files[i]);
//       fclose(fp);
//     } else if (!(getFlagVal(*flag, 's'))) {
//       fprintf(stderr, "s21_grep: %s: No such file or directory", flag->files[i]);
//     }
//     }
// }
 
void print_arr(char *list[]) {
  int i = 0;
  while (list[i]) {
    putc('\t', stdout);
    puts(list[i]);
    i++;
  }
}

void print_debug(t_flags flag) {
  if (flag.filesCount) {
    printf("files count: %d\n", flag.filesCount);
    puts("patterns:");
    print_arr(flag.patterns);
    puts("patterns files:");
    print_arr(flag.patterns_files);
    puts("files:");
    print_arr(flag.files);
    puts("final pattern:");
    if (flag.pattern) puts(flag.pattern);
  }
}

int main(int argc, char **argv) {
    t_flags flag = {0};
    initFlags(&flag);
    optionScan(argc, argv, &flag);
    // grep_it(&flag);
    print_debug(flag);
    return 0;
}
