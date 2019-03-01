include $(APEX)/src/$(OS).inc

TARGET = sed
SRCS = $(wildcard *.c)
OBJ = ${SRCS:.c=.o}

CFLAGS += -I.

.PHONY: all clean

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $(SRCS)

$(TARGET): $(OBJ)
	$(LD) -static -nostdlib -z noseparated-code -z max-page-size=0x200000 -o $(TARGET) $(APEXLIB)/crt0.o $(APEXLIB)/crti.o $(APEXLIB)/crtn.o $(OBJ) -L$(APEXLIB) -L$(HARVEYLIB) -lap -lc

install:
	cp $(TARGET) $(APEXBIN)

clean:
	rm -f $(OBJ) $(TARGET)
