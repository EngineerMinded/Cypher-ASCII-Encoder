# Make file for Cypher program
# From this version on out: use one of these and use this  format

CC=gcc

CFLAGS = -c -Wall

all: prog encode decode clean 

prog: prog.o codec.o
	$(CC) prog.o codec.o -o cypher

encode: encode.o codec.o
	$(CC)  encode.o codec.o -o encode
	
decode: decode.o codec.o
	$(CC) decode.o codec.o -o decode

prog.o: prog.c
	$(CC) $(CFLAGS) prog.c 

encode.o: encode.c
	$(CC) $(CFLAGS) encode.c

decode.o: decode.c 
	$(CC) $(CFLAGS) decode.c 

codec.o: codec.c
	$(CC) $(CFLAGS) codec.c

clean:
	rm -rf *.o