include ../../../Makefile.inc

CFLAGS += -I../internal
CP = cp

.PHONY: all

all: crt0.o crt1.o crti.o crtn.o

crt0.o: crt0.S
	$(CC) $(CFLAGS) -c crt0.S
	$(CP) crt0.o $(LIB)/

crt1.o: crt1.c
	$(CC) $(CFLAGS) -c crt1.c
	$(CP) crt1.o $(LIB)/

crti.o: crti.s
	$(CC) $(CFLAGS) -c crti.s
	$(CP) crti.o $(LIB)/

crtn.o: crtn.s
	$(CC) $(CFLAGS) -c crtn.s
	$(CP) crtn.o $(LIB)/

clean:
	rm -f *.o
