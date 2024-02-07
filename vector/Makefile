CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c99
SRCS=vector.c vector2.c
OBJS=$(SRCS:.c=.o)
BIN=vector

library: libvector.a

libvector.a: vector.o vector2.o
		ar rcs $@ $^

all: $(BIN)

$(BIN): $(OBJS)

clean:
	$(RM) $(BIN) $(OBJS) *.a
