# Make file for Cypher program
# From this version on out: use one of these and use this  format

CC=gcc

CFLAGS = -c -Wall

all: prog clean

prog: Cypher.o encode.o
	$(CC) Cypher3_5.o encode.o -o cypher

Cypher.o: Cypher3_5.c 
	$(CC) $(CFLAGS) Cypher3_5.c 

encode.o: encode.c 
	$(CC) $(CFLAGS) encode.c 

clean:
	rm -rf *.o