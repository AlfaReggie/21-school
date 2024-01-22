#ifndef FUNC_H
#define FUNC_H

void cat_print(FILE *file, flags *flag);
void cat_file(int argc, char **argv, flags *flag);
void scanFlags(char *args, flags *flag);
char parse_flags(int argc, char **argv, flags *flag);



#endif  // FUNC_H
