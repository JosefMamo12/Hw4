CC=gcc 
FLAGS= -Wall -g
AR= ar
all:frequency

frequency: main.o trie.o
	$(CC) $(FLAGS) -o frequency main.o trie.o
 
main.o: main.c
	$(CC) $(FLAGS) -c main.c

trie.o: trie.c trie.h
	$(CC) $(FLAGS) -c trie.c

 .PHONY:
	clean all frequency

clean:
	rm -rf *o run main