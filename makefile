# Make file for Cypher program
# From this version on out: use one of these and use this  format

CC=gcc

CFLAGS = -c -Wall

# all programs to be made and clean the output files
all: prog encode decode clean 

prog: prog.o codec.o  codekey.o linkedlist.o
	$(CC) prog.o codec.o codekey.o linkedlist.o -o cypher

encode: encode.o codec.o codekey.o linkedlist.o
	$(CC)  encode.o codec.o codekey.o linkedlist.o -o encode
	
decode: decode.o codec.o codekey.o linkedlist.o
	$(CC) decode.o codec.o codekey.o linkedlist.o -o decode

prog.o: prog.c
	$(CC) $(CFLAGS) prog.c 

encode.o: encode.c
	$(CC) $(CFLAGS) encode.c

decode.o: decode.c 
	$(CC) $(CFLAGS) decode.c 

codec.o: codec.c
	$(CC) $(CFLAGS) codec.c

codekey.o: codekey.c
	$(CC) $(CFLAGS) codekey.c

linkedlist.o: linkedlist.c
	$(CC) $(CFLAGS) linkedlist.c

clean:
	rm -rf *.o