static void arg_scanner(int argc, char **argv, struct args *args) {
  for (; argc > 1; --argc, ++argv) {
    if (argv[1][0] == '-') {
      switch (argv[1][1]) {
        case 'b':
          args->b = true;
          break;
        case 'e':
          args->e = true;
          args->v = true;
          break;
        case 'E':
          args->e = true;
          break;
        case 'n':
          args->n = true;
          break;
        case 't':
          args->t = true;
          args->v = true;
          break;
        case 'T':
          args->t = true;
          break;
        case 's':
          args->s = true;
          break;
        case 'v':
          args->v = true;
          break;
        default:
          if (argv[1][1] == '-') {
            if (!strcmp(argv[1], "--number-nonblank"))
              args->b = true;
            else if (!strcmp(argv[1], "--number"))
              args->n = true;
            else if (!strcmp(argv[1], "--squeeze-blank"))
              args->s = true;
          }
      }
    }
  }
}

static void init_args(struct args *args) {
  args->b = false;
  args->e = false;
  args->n = false;
  args->s = false;
  args->t = false;
  args->v = false;
}

static void cat(FILE *fp, struct args *args) {
  static int line;
  int gobble = 0;
  int ch, prev;

  for (prev = '\n'; (ch = getc(fp)) != EOF; prev = ch) {
    if (prev == '\n') {
      if (args->s) {
        if (ch == '\n') {
          if (gobble) continue;
          gobble = 1;
        } else
          gobble = 0;
      }
      if (args->n) {
        if (!args->b || ch != '\n')
          fprintf(stdout, "%6d\t", ++line);
        else if (args->e && !args->b)
          fprintf(stdout, "%6s\t", "");
      } else if (args->b && ch != '\n')
        fprintf(stdout, "%6d\t", ++line);
    }
    if (ch == '\n') {
      if (args->e)
        if (putchar('$') == EOF) break;
    } else if (ch == '\t') {
      if (args->t) {
        if (putchar('^') == EOF || putchar('I') == EOF) break;
        continue;
      }
    } else if (args->v) {
      if (!isascii(ch)) {
        if (putchar('M') == EOF || putchar('-') == EOF) break;
        ch = toascii(ch);
      }
      if (iscntrl(ch)) {
        if (putchar('^') == EOF ||
            putchar(ch == '\177' ? '?' : ch | 0100) == EOF)
          break;
        continue;
      }
    }
    if (putchar(ch) == EOF) break;
  }
}

static int scat(char **argv, struct args *args) {
  int retval;
  FILE *fp;
  do {
    argv++;
    if (*argv) {
      if ((fp = fopen(*argv, "r")) == NULL) {
        retval = NO_FILE;
        continue;
      } else {
        cat(fp, args);
        fclose(fp);
        retval = EXIT_SUCCESS;
      }
    }

  } while (*argv);

  return retval;
}

int main(int argc, char **argv) {
  if (argc == 1) return NO_OPT;
  struct args args;
  init_args(&args);
  arg_scanner(argc, argv, &args);
  int retval = scat(argv, &args);

  return retval;
}
