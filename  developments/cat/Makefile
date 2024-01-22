CC=gcc
CFLAGS=-Wall -Wextra -Werror
clang_path= ../../materials/linters/
OBJS = $(patsubst %.c, %.o, s21_cat.c)


all: s21_cat


s21_cat: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@


%.o: %.c Makefile s21_cat.h
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf *.o *.out *.a s21_cat
	rm -rf .clang-format

testing:
	mv s21_cat ./tests
	cd ./tests; chmod u=rwx run_tests.sh ; ./run_tests.sh
	rm ./tests/s21_cat

check:
	cppcheck --enable=all --suppress=missingIncludeSystem ../cat
	valgrind --tool=memcheck --leak-check=yes -s ./s21_cat s21_cat.c 
	
format:
	cp $(clang_path).clang-format ./
	clang-format -n *.c *.h

clang_replace:
	cp $(clang_path).clang-format ./
	clang-format -i *.c *.h

rebuild: clean all