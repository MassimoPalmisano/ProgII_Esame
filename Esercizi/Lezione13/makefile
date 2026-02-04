CC = g++
CFLAGS = -Wall -g
DEST = moduli
ORIG = main.cc file.cc 

run: $(ORIG)
	$(CC) $(CFLAGS) $^ -o $(DEST).exe

clean: 
	rm -f $(DEST).exe