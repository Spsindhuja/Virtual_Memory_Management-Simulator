CC=gcc
CFLAGS=-Wall

all:
	$(CC) main.c memory.c algorithms.c -o simulator $(CFLAGS)

run:
	./simulator

clean:
	rm -f simulator