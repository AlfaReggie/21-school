CFLAGS = -Wall -Wextra -Wpedantic -Werror -pedantic-errors -std=c11
CC = gcc $(CFLAGS)
TARGET = s21_cat
SRCS = s21_cat.c func.c
OBJS = $(SRCS:.c=.o) 

all: $(TARGET) 

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

clean:
	rm -rf $(OBJS) $(TARGET)