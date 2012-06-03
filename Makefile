CFLAGS = -Wall -pedantic -ansi -lm -g
CC = gcc

ISI: termos.o ep1-329.c
	$(CC) $(CFLAGS) ep1-329.c termos.o -o ISI

termos.o: termos.c
