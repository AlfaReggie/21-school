CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
TARGET = s21_cat
SRCS = s21_cat.c CatAscii.c
OBJS = $(SRCS:.c=.o) 

all: $(TARGET) 

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -rf $(OBJS) $(TARGET)