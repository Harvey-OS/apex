include ../../../$(OS).inc

CFLAGS += -I../internal
CP = cp

.PHONY: all

all: crt1.o crti.o crtn.o clean

crt1.o: crt1.S
	$(CC) $(CFLAGS) -c crt1.S
	$(CP) crt1.o $(APEXLIB)/

crti.o: crti.s
	$(CC) $(CFLAGS) -c crti.s
	$(CP) crti.o $(APEXLIB)/

crtn.o: crtn.s
	$(CC) $(CFLAGS) -c crtn.s
	$(CP) crtn.o $(APEXLIB)/

clean:
	rm -f *.o
