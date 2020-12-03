CC=gcc
CFLAGS=-W -Wall -ansi -pedantic -std=c99
LDFLAGS=
EXEC=day3


all: $(EXEC) clean

day3: day3.o main.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)
		
clean:
	rm -rf *.o
	
mrproper: clean
	rm -rf $(EXEC)
