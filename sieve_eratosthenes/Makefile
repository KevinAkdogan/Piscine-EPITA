CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -pedantic

all: sieve.o

sieve: main.o sieve.o
	$(CC) main.o sieve.o sieve

main.o:
	$(CC) $(CFLAGS) -c -o main.o main.c

main.o: sieve.c
	$(CC) $(CFLAGS) -c -o sieve.o sieve.c
