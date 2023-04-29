CC = gcc
CFLAGS = -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self 
NAME = Testing

SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,%,$(SRCS))

run: all 
	python3 tested.py


all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) -o $(NAME)  $< -lm
	./$(NAME)

clean:
	rm -f $(PROGS) $(NAME)
	rm -f partidos.txt