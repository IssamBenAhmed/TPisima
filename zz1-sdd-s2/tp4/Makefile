# Makefile robuste pour tp4

CC := gcc
CFLAGS := -Wall -Wextra -g
LDLIBS :=

SRC := $(wildcard *.c)
OBJ := $(SRC:.c=.o)

.PHONY: all clean

all: main

main: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	find . -type f -name "*.o" -print0 | xargs -0 rm -f
	rm -f main
