CC=gcc
CFLAGS=-W -Wall -ansi -pedantic -std=c99
LDFLAGS=
EXEC=day2


all: $(EXEC) clean

day2: day2.o main.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)
		
clean:
	rm -rf *.o
	
mrproper: clean
	rm -rf $(EXEC)
