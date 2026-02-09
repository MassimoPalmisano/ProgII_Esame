CC = g++
CFLAGS = -Wall -g
DEST = esame
ORIG = compito.cc tipo.cc liste.cc 

comp: $(ORIG)
	$(CC) $(CFLAGS) $^ -o $(DEST).exe

clean: 
	rm *.exe

run:
	./$(DEST).exe