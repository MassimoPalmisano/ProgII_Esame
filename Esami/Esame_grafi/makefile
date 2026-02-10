CC = g++
CFLAGS = -Wall -g
DEST = esame
ORIG = compito.o tipo.o grafo.o 

all:
	make hotel grafo compito comp

comp: $(ORIG)
	$(CC) $(CFLAGS) $^ -o $(DEST).exe

clean: 
	rm *.exe *.o

run:
	./$(DEST).exe

hotel: tipo.cc
	$(CC) -c $^

grafo: grafo.cc
	$(CC) -c $^

compito: compito.cc
	$(CC) -c $^