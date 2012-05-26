CFLAGS = -Wall -pedantic -ansi -lm -g
all: ISI

termos.o: termos.c
	gcc $(CFLAGS) -c termos.c -o termos.o

ep1-329.o: ep1-329.c
	gcc $(CFLAGS) -c ep1-329.c -o ep1-329.o

ISI: termos.o ep1-329.o
	gcc $(CFLAGS) ep1-329.o termos.o -o ISI
