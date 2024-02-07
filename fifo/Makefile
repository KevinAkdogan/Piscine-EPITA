CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c99 -pedantic
SRCS=fifo.c fifo2.c
OBJS=$(SRCS:.c=.o)
BIN=fifo

library: libfifo.a

libfifo.a: fifo.o fifo2.o
		ar rcs $@ $^

all: $(BIN)

$(BIN): $(OBJS)

clean:
	$(RM) $(BIN) $(OBJS) *.a
