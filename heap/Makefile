CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c99 -pedantic
SRCS=create.c add.c del.c pop.c print.c
OBJS=$(SRCS:.c=.o)
BIN=fifo

library: libheap.a

libheap.a: create.o add.o del.o pop.o print.o
		ar rcs $@ $^

all: $(BIN)

$(BIN): $(OBJS)

clean:
	$(RM) $(BIN) $(OBJS) *.a
