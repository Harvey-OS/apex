include $(APEX)/src/$(OS).inc

CFLAGS += -I../internal
CP = cp

.PHONY: all

all: crt0.o crti.o crtn.o clean

crt0.o: crt0.c
	$(CC) $(CFLAGS) -c crt0.c
	$(CP) crt0.o $(APEXLIB)/

crti.o: crti.s
	$(CC) $(CFLAGS) -c crti.s
	$(CP) crti.o $(APEXLIB)/

crtn.o: crtn.s
	$(CC) $(CFLAGS) -c crtn.s
	$(CP) crtn.o $(APEXLIB)/

clean:
	rm -f *.o
