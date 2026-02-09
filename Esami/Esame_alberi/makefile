CC = g++
CFLAGS = -Wall -g
DEST = esame
ORIG = compito.o hotel.o bst.o 

all: $(ORIG)
	$(CC) $(CFLAGS) $^ -o $(DEST).exe

clean: 
	rm *.exe

run:
	./$(DEST).exe

hotel: hotel.cc
	$(CC) -c $^

bst: bst.cc
	$(CC) -c $^

compito: compito.cc
	$(CC) -c $^