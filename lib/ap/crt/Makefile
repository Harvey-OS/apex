include ../../../Makefile.inc

CFLAGS += -I../internal
CP = cp

.PHONY: all

all: crt1.o crti.o crtn.o clean

crt1.o: crt1.S
	$(CC) $(CFLAGS) -c crt1.S
	$(CP) crt1.o $(LIB)/

crti.o: crti.s
	$(CC) $(CFLAGS) -c crti.s
	$(CP) crti.o $(LIB)/

crtn.o: crtn.s
	$(CC) $(CFLAGS) -c crtn.s
	$(CP) crtn.o $(LIB)/

clean:
	rm -f *.o
