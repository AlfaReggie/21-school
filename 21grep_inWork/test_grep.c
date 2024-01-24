#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <getopt.h>
#include <regex.h>

#define FLAGS_COUNT 10
#define SIZE 4096

typedef struct s_flags {

    char* patterns_files[SIZE];
    char* files[SIZE];
    char* pattern[SIZE];
    
    int e;  // Шаблон |
    int i;  // Игнорирует различия регистра.  |
    int v;  // Инвертирует смысл поиска соответствий. |
    int c;  // Выводит только количество совпадающих строк. |
    int l;  // Выводит только совпадающие файлы.  |
    int n;  // Предваряет каждую строку вывода номером строки из файла ввода. |
    int h;  // Выводит совпадающие строки, не предваряя их именами файлов. |
    int s;  // Подавляет сообщения об ошибках о несуществующих |
    int f;  // Получает регулярные выражения из файла. |
    int o;  // Печатает только совпадающие (непустые) части совпавшей строки. |

} t_flags;

void* safety_malloc(size_t size) {
    void* pointer = malloc(size);
    if (!pointer)
        exit(1);
    return pointer;
}

void* safety_realloc(void* ptr, size_t newsize) {
    ptr = realloc(ptr, newsize);
        if (!ptr)
            exit(1);
    return ptr;
}

void execute(int argc, char **argv)
{
    int opt = 0;
    int num_flags = 0;
    t_flags* s_flags = NULL;

    while ((opt = getopt(argc, argv, "e:ivclnhsf:o")) != -1)
    {
        if (opt == '?')
            exit(2);
        if (!s_flags)
            arrFlags = (t_flags*)safety_malloc(sizeof(t_flags));
        else
            arrFlags = (t_flags*)safety_realloc(s_flags, sizeof(t_flags)*(num_flags+1));

        printf("Start\n");
        printf("opt: %c\n", (char)opt);
        printf("optarg: %s\n", optarg);
        t_flags. = opt;
        _sflags[num_flags].template = optarg ? strdup(optarg) : optarg;
        printf("flag[%d].flag: %c\n", num_flags, flags[num_flags].flag);
        printf("flag[%d].template: %s\n", num_flags, flags[num_flags].template);
        printf("num_flags: %d\n\n", num_flags);
        num_flags++;
    }
}

int main(int argc, char** argv) {
    execute(argc, argv);
    return 0;
}