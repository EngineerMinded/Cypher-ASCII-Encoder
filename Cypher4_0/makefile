# Make file for Cypher program
# From this version on out: use one of these and use this  format

CC=gcc

CFLAGS = -c -Wall

all: prog encode decode clean 

prog: prog.o codec.o
	$(CC) prog.c codec.c -o cypher

encode:
	$(CC)  encode.c codec.c -o encode
	
decode: decode.o codec.o
	$(CC) decode.c codec.c -o decode

clean:
	rm -rf *.o